class CfgPatches
{
	class BasicBombsDefine
	{
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class CfgMods
{
	class BasicBombsDefine
	{
		dir="BasicBombsDefine";
        name="BasicBombs";
        type="mod";
	    dependencies[]={"GameLib", "Game", "World", "Mission"};
	    class defs
	    {
			class gameLibScriptModule
			{
				value = "";
				files[] = {
					"BasicBombsDefine/scripts/Common"
					};
			};
			class gameScriptModule
            {
				value = "";
                files[]={
					"BasicBombsDefine/scripts/Common"
					};
            };
			
			class worldScriptModule
            {
                value="";
                files[]={ 
					"BasicBombsDefine/scripts/Common"
				};
            };
			
	        class missionScriptModule
            {
                value="";
                files[]={
					"BasicBombsDefine/scripts/Common"
				};
            };
        };
    };
};