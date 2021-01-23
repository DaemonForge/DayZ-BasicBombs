class IngitePipeBombInHand extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Ingite Pipe";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1;//animation length in relative time units
		m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"PetrolLighter");//you can insert multiple ingredients this way
		InsertIngredient(0,"Matchbox");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		//ingredient 2
		InsertIngredient(1,"BB_PipeBomb");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
	
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ItemBase item = ItemBase.Cast(ingredients[0]);
		BB_PipeBomb target_item = BB_PipeBomb.Cast(ingredients[1]);
		if (item && target_item){
			if ( item.CanIgniteItem( target_item ) && !target_item.IsIgnited() && target_item.GetFuseCount() > 1)
			{
				return true;
			} else {
				Print("Invalid Coniditions for IngitePipeBombInHand");
			}
		} else {
			Print("Invalid Items for IngitePipeBombInHand");
		}
		return false;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase item = ItemBase.Cast(ingredients[0]);
		BB_PipeBomb target_item = BB_PipeBomb.Cast(ingredients[1]);
		PlayerBase thePlayer = PlayerBase.Cast(player);
		if (item && target_item && thePlayer){
			item.OnIgnitedTarget(target_item);
			target_item.IngiteFromHand(thePlayer);
		}
		
	}
};