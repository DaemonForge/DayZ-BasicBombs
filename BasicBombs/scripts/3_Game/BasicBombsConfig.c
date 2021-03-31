class BasicBombsConfig
{
	protected static string DirPATH = "$profile:BasicBombs";
	protected static string ConfigPATH = DirPATH + "\\settings.json";
	string ConfigVersion = "1";
	
	float FirstCapOnPipeSpawnRate = 1.0;
	float SecondCapOnPipeSpawnRate = 0.5;
	float HackSawDamageOnCraft = 33;
	
	
	void Load(){
		Print("[BasicBombs] Loading Config");
		if (GetGame().IsServer()){
			if (FileExist(ConfigPATH)){ //If config exist load File
			    JsonFileLoader<BasicBombsConfig>.JsonLoadFile(ConfigPATH, this);
				if (ConfigVersion != "1"){
					ConfigVersion = "1";
					Save();
				}
			}else{ //File does not exist create file
				if (!FileExist(DirPATH)){
					MakeDirectory(DirPATH);
				}
				Save();
			}
		}
	}
	
	void Save(){
		JsonFileLoader<BasicBombsConfig>.JsonSaveFile(ConfigPATH, this);
	}

	float GetHackSawDamage(){
		return -HackSawDamageOnCraft;
	}
	
	
}

ref BasicBombsConfig m_BasicBombsConfig;

//Helper function to return Config
static BasicBombsConfig GetBasicBombsConfig()
{
	if (!m_BasicBombsConfig)
	{
		m_BasicBombsConfig = new BasicBombsConfig;
			
		if ( GetGame().IsServer() ){
			m_BasicBombsConfig.Load();
		}
	}
	return m_BasicBombsConfig;
};