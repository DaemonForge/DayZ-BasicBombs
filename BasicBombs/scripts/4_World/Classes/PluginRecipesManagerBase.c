modded class PluginRecipesManagerBase extends PluginBase
{	
	void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new MakePipeBomb);
		RegisterRecipe(new MakePipeBombShell);
		RegisterRecipe(new MakeBBFuse);
		RegisterRecipe(new IngitePipeBombInHand);
		
	}
};