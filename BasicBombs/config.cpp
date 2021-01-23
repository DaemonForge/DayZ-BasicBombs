class CfgPatches
{
	class BasicBombs
	{
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Weapons_Explosives",
			"BasicBombsDefine"
		};
	};
};

class CfgMods
{
	class BasicBombs
	{
		dir="BasicBombs";
        name="BasicBombs";
        credits="DaemonForge, Dumpgrah";
        author="DaemonForge";
        authorID="0";
        version="0.1";
        extra=0;
        type = "Mod";
	    dependencies[]={"Game","World"};
	    class defs
	    {
			class gameScriptModule
            {
                value="";
                files[]={ 
					"BasicBombs/scripts/3_Game" 
				};
            };
			class worldScriptModule
            {
                value="";
                files[]={ 
					"BasicBombs/scripts/4_World" 
				};
            };
        };
    };
};
class CfgAmmo
{
	class DefaultAmmo;
	class PipeBomb_AmmoLow: DefaultAmmo
	{
        hit=0.8;
		indirectHit = 1;
		indirectHitRange = 2;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 0.9;
			class Health
			{
				damage = 100;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 40;
			};
		};
		class NoiseExplosion
		{
			strength = 20;
			type = "shot";
		};
	};
	class PipeBomb_AmmoHigh: DefaultAmmo
	{
        hit=0.9;
		indirectHit = 1;
		indirectHitRange = 5;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 0.6;
			class Health
			{
				damage = 300;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 100;
			};
		};
		class NoiseExplosion
		{
			strength = 300;
			type = "shot";
		};
	};
	class PipeBomb_Ammo: DefaultAmmo
	{
        hit=0.8;
		indirectHit = 1;
		indirectHitRange = 4;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 0.6;
			class Health
			{
				damage = 200;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 30;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
};
class CfgSlots
{
	class Slot_Att_BB_Fuse
	{
		name = "Att_BB_Fuse";
		displayName = "Fuse";
		selection = "att_BB_Fuse";
		ghostIcon = "rags";
		stackMax = 3;
	};
	class Slot_Att_BB_Cap
	{
		name = "Att_BB_Cap";
		displayName = "Cap";
		selection = "att_BB_Cap";
	};
	class Slot_Att_BB_BlastCap
	{
		name = "Att_BB_BlastCap";
		displayName = "Blast Cap";
		selection = "att_BB_Cap";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Grenade_Base;
	class Bottle_Base;
	
	class BB_PipeBomb: Grenade_Base
	{
		scope = 2;
		displayName = "Basic Pipe Bomb";
		descriptionShort = "A Basic Pipe Bomb, with a fuse you could light this with some matches";
		model = "\BasicBombs\data\BB_PipeBomb.p3d";
		rotationFlags = 1;
		weight = 3600;
		itemSize[] = {1,5};
		ammoType = "PipeBomb_Ammo";
		itemBehaviour = 1;
		attachments[] = {"Att_BB_Fuse"};
		simpleHiddenSelections[] = {
			"BlastingCap",
			"EndCap",
			"Pipe",
			"Placing",
			"Rag",
			"SideCap"
		};
        hiddenSelections[]=
        {
			"BlastingCap",
			"EndCap",
			"Pipe",
			"Placing",
			"Rag",
			"SideCap"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\metal_pipe.rvmat"}},{0.7,{"DZ\gear\tools\data\metal_pipe.rvmat"}},{0.5,{"DZ\gear\tools\data\metal_pipe_damage.rvmat"}},{0.3,{"DZ\gear\tools\data\metal_pipe_damage.rvmat"}},{0.0,{"DZ\gear\tools\data\metal_pipe_destruct.rvmat"}}};
				};
			};
		};
		

	};
		
	class BB_PipeBomb_Shell: Bottle_Base
	{
		scope = 2;
		displayName = "Empty Pipe";
		descriptionShort = "A short cut pipe. Useful for making pipe bombs?";
		model = "\BasicBombs\data\BB_PipeBomb.p3d";
		rotationFlags = 1;
		weight = 2800;
		itemSize[] = {1,5};
		fragility = 0.001;
		itemBehaviour = 1;
		destroyOnEmpty = 0;
		canBeSplit = 0;
		varQuantityDestroyOnMin = 0;
		varLiquidTypeInit = 8192;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 500.0;
		attachments[] = {"Att_BB_Fuse", "Att_BB_Cap", "Att_BB_BlastCap"};
		simpleHiddenSelections[] = {
			"BlastingCap",
			"EndCap",
			"Pipe",
			"Placing",
			"Rag",
			"SideCap"
		};
        hiddenSelections[]=
        {
			"BlastingCap",
			"EndCap",
			"Pipe",
			"Placing",
			"Rag",
			"SideCap"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\metal_pipe.rvmat"}},{0.7,{"DZ\gear\tools\data\metal_pipe.rvmat"}},{0.5,{"DZ\gear\tools\data\metal_pipe_damage.rvmat"}},{0.3,{"DZ\gear\tools\data\metal_pipe_damage.rvmat"}},{0.0,{"DZ\gear\tools\data\metal_pipe_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset = "crowbar_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BB_Fuse: Inventory_Base
	{
		scope = 2;
		displayName = "Gas Soaked Rag";
		descriptionShort = "A Rag soaked in gasoline";
		model = "\dz\gear\consumables\Rags.p3d";
		weight = 30;
		itemSize[] = {1,2};
		inventorySlot[] = {"Att_BB_Fuse"};
		rotationFlags = 17;
		canBeSplit = 1;
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varStackMax = 1.0;
		varQuantityDestroyOnMin = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\consumables\data\rags_bandages.rvmat"}},{0.7,{"DZ\gear\consumables\data\rags_bandages.rvmat"}},{0.5,{"DZ\gear\consumables\data\rags_bandages_damage.rvmat"}},{0.3,{"DZ\gear\consumables\data\rags_bandages_damage.rvmat"}},{0.0,{"DZ\gear\consumables\data\rags_bandages_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	
	class BB_PipeCap: Inventory_Base
	{
		scope = 2;
		displayName = "Pipe Cap";
		descriptionShort = "A small metal piece that can attach to the end of a pipe";
		model = "\BasicBombs\data\BB_PipeCap.p3d";
		weight = 100;
		itemSize[] = {1,1};
		inventorySlot[] = {"Att_BB_Cap", "Att_BB_BlastCap"};
		simpleHiddenSelections[] = {
			"SideCap"
		};
        hiddenSelections[]=
        {
			"SideCap"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\metal_pipe.rvmat"}},{0.7,{"DZ\gear\tools\data\metal_pipe.rvmat"}},{0.5,{"DZ\gear\tools\data\metal_pipe_damage.rvmat"}},{0.3,{"DZ\gear\tools\data\metal_pipe_damage.rvmat"}},{0.0,{"DZ\gear\tools\data\metal_pipe_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundSet = "crowbar_drop_SoundSet";
					id = 797;
				};
			};
		};
	};
};

