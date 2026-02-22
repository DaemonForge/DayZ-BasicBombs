modded class PluginRecipesManagerBase extends PluginBase
{	
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new MakePipeBomb);
		RegisterRecipe(new MakePipeBombShell);
		RegisterRecipe(new MakeBBFuse);
		RegisterRecipe(new IngitePipeBombInHand);
		
	}
};