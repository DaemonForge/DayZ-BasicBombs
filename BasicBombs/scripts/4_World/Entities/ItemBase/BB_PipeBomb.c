class BB_PipeBomb extends Grenade_Base
{
	protected Particle m_SparkEfx;	// Refernce to particle effect
	
	protected string IgnitedByGUID = "";
	protected string IgnitedById = "";
	
	bool m_isIgnited = false;
	bool m_hasExploded = false;
	bool m_isIgnited_Local = false;
	bool m_hasExploded_Local = false;
	
	void BB_PipeBomb()
	{
		RegisterNetSyncVariableBool("m_isIgnited");
		RegisterNetSyncVariableBool("m_hasExploded");
		SetAmmoType("");
		SetFuseDelay(4);
		SetParticleExplosion(ParticleList.RGD5);
		
		ShowSimpleSelection("SideCap", false);
		ShowSimpleSelection("Rag", false);
		ShowSimpleSelection("Placing", false);
		
		Print(GetMemoryPointPos("light"));
	}

	void ~BB_PipeBomb() {
		OnBBStopIngitedClient();
	}
	
	void SetIgnitedByGUID(string guid, string steamId = ""){
		IgnitedByGUID = guid;
		IgnitedById = steamId;
	}
	
	string GetIgnitedByGUID(){
		return IgnitedByGUID;
	}
	
	string GetIgnitedBySteamId(){
		return IgnitedById;
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( m_isIgnited != m_isIgnited_Local ){
			m_isIgnited_Local = m_isIgnited;
			if ((GetGame().IsClient() || !GetGame().IsMultiplayer()) && m_isIgnited){
				OnBBIngitedClient();
			} else if ((GetGame().IsClient() || !GetGame().IsMultiplayer()) && !m_isIgnited){
				OnBBStopIngitedClient();
			}
		}
		
		if ( m_hasExploded != m_hasExploded_Local && m_hasExploded ){
			m_isIgnited_Local = m_isIgnited;
			if ((GetGame().IsClient() || !GetGame().IsMultiplayer()) && m_SparkEfx) {
				OnBBExplodeClient();
			}
			
		}
	}
	
	void OnBBIngitedClient(){
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){ //Just a double check
			m_SparkEfx = Particle.PlayOnObject(ParticleList.BB_SPARKS, this, GetMemoryPointPos("light"));
		}
	}
	
	void OnBBStopIngitedClient(){
		if (m_SparkEfx) {
			m_SparkEfx.Stop();
		}
	}
	
	void OnBBExplodeClient(){
		OnBBStopIngitedClient();
	}
	
	private void ShowSimpleSelection(string selectionName, bool hide = true)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	
	override bool CanBeIgnitedBy( EntityAI igniter = NULL )
	{
		if ( GetHierarchyParent() || IsIgnited() ) return false;
		
		return HasFuse();
	}
	
	bool IsIgnited(){
		return m_isIgnited;
	}
	
	bool HasFuse(){		
		if (GetFuseCount() > 0){
			return true;
		}
		
		return false;
	}
	
	override bool CanReleaseAttachment(EntityAI attachment){
		if (IsIgnited()){
			return false;
		}
		return super.CanReleaseAttachment(attachment);
	}
	
	override bool IsTargetIgnitionSuccessful(EntityAI item_target)
	{
		int ignitionSuccessful = Math.RandomInt(1,10);
		return (ignitionSuccessful > 3);
	}
	
	override void OnIgnitedThis( EntityAI fire_source )
	{
		ItemBase item = ItemBase.Cast(fire_source);
		if (item){
			PlayerBase player = PlayerBase.Cast(item.GetHierarchyRootPlayer());
			if (player && player.GetIdentity()){
				SetIgnitedByGUID(player.GetIdentity().GetId(),player.GetIdentity().GetPlainId());
			}
		}
		
		int FuseTime = ((GetFuseCount() + Math.RandomInt(0,3)) * Math.RandomInt(2,3)) + Math.RandomInt(3,6);

		SetFuseDelay(FuseTime);
		m_isIgnited = true;
		SetSynchDirty();
		Activate();
	}

	void IngiteFromHand(PlayerBase player){
		PlayerBase thePlayer = PlayerBase.Cast(player);
		if (thePlayer && thePlayer.GetIdentity()){
			SetIgnitedByGUID(thePlayer.GetIdentity().GetId(),thePlayer.GetIdentity().GetPlainId());
		}
		
		int FuseTime = ((GetFuseCount() + Math.RandomInt(0,3)) * Math.RandomInt(2,3)) + Math.RandomInt(4,7); //Extra second added for throwing

		SetFuseDelay(FuseTime);
		m_isIgnited = true;
		SetSynchDirty();
		Activate();
	}
		
	
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionUnpin);
		RemoveAction(ActionPin);
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	
	override protected void ExplodeGrenade(EGrenadeType grenade_type)
	{
		if (m_hasExploded) {
			return;
		}
		
		vector CurPos = this.GetPosition();
		
		vector AdjustedPos = CurPos + "0 0.15 0";
		
		this.SetPosition(AdjustedPos);
		
		float rndExplosion = Math.RandomFloat(0,1);
		if (GetHealth("","") > 260){
			rndExplosion = rndExplosion + 0.15;
		} else if (GetHealth("","") > 220){
			rndExplosion = rndExplosion + 0.1;
		} else if (GetHealth("","") > 160){
			rndExplosion = rndExplosion + 0.05;
		}
		if ( rndExplosion <= 0.15){
			m_isIgnited = false;
			SetSynchDirty();
			if (m_isIgnited){
				ItemBase theFuse;
				if (Class.CastTo(theFuse, this.FindAttachmentBySlotName("Att_BB_Fuse"))){
					GetGame().ObjectDelete(theFuse);
				}
			}
			GetGame().AdminLog("[BasicBombs] " + this.GetType() + " Explosion - Dud: " + rndExplosion + " - Ignited By: " + IgnitedById + " - At: " + this.GetPosition());

			return;
		} else if ( rndExplosion <= 0.40){
			m_hasExploded = true;
			Explode(DT_EXPLOSION, "PipeBomb_AmmoLow");
			GetGame().AdminLog("[BasicBombs] " + this.GetType() + " Explosion - Low: " + rndExplosion + " - Ignited By: " + IgnitedById + " - At: " + this.GetPosition());
		} else if ( rndExplosion >= 0.95){
			m_hasExploded = true;
			Explode(DT_EXPLOSION, "PipeBomb_AmmoHigh");
			GetGame().AdminLog("[BasicBombs] " + this.GetType() + " Explosion - High: " + rndExplosion + " - Ignited By: " + IgnitedById + " - At: " + this.GetPosition());
		} else {
			m_hasExploded = true;
			Explode(DT_EXPLOSION, "");
			GetGame().AdminLog("[BasicBombs] " + this.GetType() + " Explosion - Mid: " + rndExplosion + " - Ignited By: " + IgnitedById + " - At: " + this.GetPosition());
		
		}
		
		
		OnExplode();
		SetSynchDirty();
		
	}
	
	
	void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		if (slot_name == "Att_BB_Fuse"){
			ShowSimpleSelection("Rag");
		}
		
	}
	
	
	void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (slot_name == "Att_BB_Fuse" && GetFuseCount() == 0){
			ShowSimpleSelection("Rag", false);
		}
	}
	
	float GetFuseCount(){
		ItemBase theFuse;
		
		if (Class.CastTo(theFuse, this.FindAttachmentBySlotName("Att_BB_Fuse"))){
			return theFuse.GetQuantity();
		}
		return 0;
	}
	
	override void AfterStoreLoad(){
		super.AfterStoreLoad();
		if (HasFuse()){
			ShowSimpleSelection("Rag");
		} else {
			ShowSimpleSelection("Rag", false);
		}
	}
		
	override void OnPlacementStarted( Man player )
    {
        super.OnPlacementStarted( player );
        
		ShowSimpleSelection("Placing", true);
		ShowSimpleSelection("Pipe", false);
		ShowSimpleSelection("SideCap", false);
		ShowSimpleSelection("BlastingCap", false);
		ShowSimpleSelection("EndCap", false);
		ShowSimpleSelection("Rag", false);
    }
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		if ((damageType == DT_EXPLOSION || damageType == DT_FIRE_ARM) && source != this && !m_hasExploded){
			int whentoExplode = Math.RandomInt(100, 900);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ExplodeGrenade, whentoExplode, false, EGrenadeType.FRAGMENTATION);
			BB_PipeBomb bomb = BB_PipeBomb.Cast(source);
			if (bomb){
				SetIgnitedByGUID(bomb.GetIgnitedByGUID(), bomb.GetIgnitedBySteamId());
			}
		}
	}
		
}



