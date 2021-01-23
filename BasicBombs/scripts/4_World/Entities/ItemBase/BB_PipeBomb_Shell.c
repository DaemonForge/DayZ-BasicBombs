class BB_PipeBomb_Shell extends Bottle_Base{
	
	
	void BB_PipeBomb_Shell(){
		
		ShowSimpleSelection("Rag", false);
		ShowSimpleSelection("EndCap", false);
		ShowSimpleSelection("BlastingCap", false);
		ShowSimpleSelection("SideCap", false);
		
		ShowSimpleSelection("Placing", false);
	}
	
	private void ShowSimpleSelection(string selectionName, bool hide = true)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	
	override bool IsContainer()
	{
		return true;
	}
	
	override string GetPouringSoundset()
	{
		return "emptyVessle_WaterBottle_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetHard()
	{
		return "pour_HardGround_WatterBottle_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetSoft()
	{
		return "pour_SoftGround_WatterBottle_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetWater()
	{
		return "pour_Water_WatterBottle_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetHard()
	{
		return "pour_End_HardGround_WatterBottle_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetSoft()
	{
		return "pour_End_SoftGround_WatterBottle_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetWater()
	{
		return "pour_End_Water_WatterBottle_SoundSet";
	}
		
	override bool IsOpen()
	{
		return true;
	}
	
	bool HasFuseAttached(){
	
		ItemBase theFuse;
		
		if (Class.CastTo(theFuse, this.FindAttachmentBySlotName("Att_BB_Fuse"))){
			return true;
		}
		
		return false;
	}
	
	bool HasBlastingCapAttached(){
	
		ItemBase aCap;
		
		if (Class.CastTo(aCap, this.FindAttachmentBySlotName("Att_BB_BlastCap"))){
			return true;
		}
		
		return false;
	}
	
	bool HasEndCapAttached(){
	
		ItemBase aCap;
		
		if (Class.CastTo(aCap, this.FindAttachmentBySlotName("Att_BB_Cap"))){
			return true;
		}
		
		return false;
	}
	
	
	void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		if (slot_name == "Att_BB_Fuse"){
			ShowSimpleSelection("Rag");
		}
		if (slot_name == "Att_BB_Cap"){
			ShowSimpleSelection("EndCap");
		}
		if (slot_name == "Att_BB_BlastCap"){
			ShowSimpleSelection("SideCap");
		}
		
	}
	
	
	void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (slot_name == "Att_BB_Fuse"){
			ShowSimpleSelection("Rag", false);
		}
		if (slot_name == "Att_BB_Cap"){
			ShowSimpleSelection("EndCap", false);
		}
		if (slot_name == "Att_BB_BlastCap"){
			ShowSimpleSelection("SideCap", false);
		}
	}
	
	override void AfterStoreLoad(){
		super.AfterStoreLoad();
		
		if (HasFuseAttached()){
			ShowSimpleSelection("Rag");
		} else {
			ShowSimpleSelection("Rag", false);
		}
		if (HasBlastingCapAttached()){
			ShowSimpleSelection("SideCap");
		} else {
			ShowSimpleSelection("SideCap", false);
		}
		if (HasEndCapAttached()){
			ShowSimpleSelection("EndCap");
		} else {
			ShowSimpleSelection("EndCap", false);
		}
	}
	
	override bool CanReleaseAttachment(EntityAI attachment){
		ItemBase EndCap;
		if (Class.CastTo(EndCap, this.FindAttachmentBySlotName("Att_BB_Cap")) && EndCap == attachment){
			if (this.GetQuantity() > 0){
				return false;
			}
		}
		return super.CanReleaseAttachment(attachment);
	}
	
	//Hack for stoping you from filling without the cap on it.
	override bool IsFullQuantity(){ 
		return !HasEndCapAttached();
	}
	
	
}