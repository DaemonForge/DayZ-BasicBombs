class MakePipeBomb extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Add Fertilize";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1;//animation length in relative time units
		m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"BB_PipeBomb_Shell");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 499;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		//ingredient 2
		InsertIngredient(1,"GardenLime");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -2000;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = 2000;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("BB_PipeBomb");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		BB_PipeBomb_Shell bomb;
		Class.CastTo(bomb, ingredients[0]);
		if (bomb){
			if (bomb.GetLiquidType() == LIQUID_GASOLINE){
			}else {
				Print("bomb does not have gas");
			}
			if (!bomb.HasFuseAttached()){
				Print("bomb does not have fuse");
			
			}
		} else {
			
			Print("bomb is NULL");
		}
		
		if ( bomb && bomb.GetLiquidType() == LIQUID_GASOLINE && bomb.HasEndCapAttached() && bomb.HasBlastingCapAttached())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		BB_PipeBomb_Shell bomb_shell;
		BB_PipeBomb bomb;
		Class.CastTo(bomb_shell, ingredients[0]);
		Class.CastTo(bomb, results[0]);
		if (bomb_shell && bomb && bomb_shell.HasFuseAttached()){
			bomb.GetInventory().CreateAttachment("BB_Fuse");
		}
	}
};


class MakePipeBombShell extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Cut Pipe";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1;//animation length in relative time units
		m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"Pipe");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		
		//ingredient 2
		InsertIngredient(1,"Hacksaw");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = -33;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 1;//-1 = disable check
		
		
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("BB_PipeBomb_Shell");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		BB_PipeBomb_Shell shell = BB_PipeBomb_Shell.Cast(results[0]);
		if (shell){
			float CreateCapWithPipe = Math.RandomFloat(0,1);
			if (CreateCapWithPipe > 0.5){
				shell.GetInventory().CreateAttachment("BB_PipeCap");
			}
		}
	}
};