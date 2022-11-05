class CfgPatches
{
	class ZenTentBags
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Camping",
			"DZ_Characters_Backpacks"
		};
	};
};

class CfgMods
{
	class ZenTentBags
	{
		dir = "ZenTentBags";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenTentBags";
		credits = "Zenarchist";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenTentBags/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenTentBags/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenTentBags/scripts/5_mission" };
			};
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	class TentBase;
	class Clothing;

	// Define large tent backpack object
	class LargeTentBackpack : Clothing
	{
		scope = 2;
		displayName = "$STR_ZEN_LARGETENT0";
		descriptionShort = "$STR_ZEN_LARGETENT1";
		model = "\dz\gear\camping\large_tent_backpack.p3d";
		inventorySlot[] +=
		{
			"Back"
		};
		itemInfo[] +=
		{
			"Clothing",
			"Back"
		};
		rotationFlags = 16;
		itemSize[] = { 10,4 };
		itemsCargoSize[] = { 0,0 };
		weight = 90000;
		varWetMax = 0.49000001;
		heatIsolation = 0.69999999;
		visibilityModifier = 0.80000001;
		soundAttType = "Military";
		randomQuantity = 4;
		class ClothingTypes
		{
			male = "dz\gear\camping\large_tent_backpack.p3d";
			female = "dz\gear\camping\large_tent_backpack.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
					transferToAttachmentsCoef = 0.5;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\camping\data\bagpack.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\camping\data\bagpack.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\camping\data\bagpack_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\camping\data\bagpack_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\camping\data\bagpack_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpBackPack_Metal_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBackPack_Metal_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "taloonbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};

	// Define tent backpack base
	class TentBackpack : Clothing
	{
		scope = 2;
		displayName = "$STR_ZEN_TENTBAG0";
		descriptionShort = "$STR_ZEN_TENTBAG1";
		model = "\dz\gear\camping\large_tent_backpack.p3d";
		inventorySlot[] +=
		{
			"Back",
			"ZenTentBag"
		};
		itemInfo[] +=
		{
			"Clothing",
			"Back"
		};
		attachments[] =
		{
			"ZenTentAttachment",
			"CookingTripod",
			"CamoNet"
		};
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"ZenTentBags\data\textures\bagpack_grey_co.paa"
		};
		rotationFlags = 16;
		itemSize[] = { 10,4 };
		itemsCargoSize[] = { 0,0 };
		weight = 2000;
		varWetMax = 0.49000001;
		heatIsolation = 0.69999999;
		visibilityModifier = 0.80000001;
		soundAttType = "Military";
		randomQuantity = 4;
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "";
				description = "";
				attachmentSlots[] =
				{
					"ZenTentAttachment",
					"CookingTripod",
					"CamoNet"
				};
				icon = "set:dayz_inventory image:cookingtripod";
			}
		}
		class ClothingTypes
		{
			male = "dz\gear\camping\large_tent_backpack.p3d";
			female = "dz\gear\camping\large_tent_backpack.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
					transferToAttachmentsCoef = 0.5;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\camping\data\bagpack.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\camping\data\bagpack.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\camping\data\bagpack_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\camping\data\bagpack_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\camping\data\bagpack_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpBackPack_Metal_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBackPack_Metal_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "taloonbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class TentBackpack_Camo : TentBackpack
	{
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenTentBags\data\textures\bagpack_camo_co.paa" };
	};
	class TentBackpack_Arctic : TentBackpack
	{
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenTentBags\data\textures\bagpack_arctic_co.paa" };
	};
	class TentBackpack_Desert : TentBackpack
	{
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenTentBags\data\textures\bagpack_desert_co.paa" };
	};
	class TentBackpack_Orel : TentBackpack
	{
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenTentBags\data\textures\bagpack_orel_co.paa" };
	};

	class Inventory_Base;
	class TentBag : Inventory_Base
	{
		scope = 2;
		displayName = "$STR_ZEN_TENTBAG0";
		descriptionShort = "$STR_ZEN_TENTBAG1";
		model = "\DZ\gear\camping\LargeTent.p3d";
		attachments[] +=
		{
			"ZenTentAttachment",
			"CookingTripod",
			"CamoNet"
		};
		inventorySlot[] +=
		{
			"Back",
			"ZenTentBag"
		};
		itemInfo[] +=
		{
			"Clothing",
			"Back"
		};
		hiddenSelections[] =
		{
			"entrancec",
			"camo",
			"bags",
			"xlights_glass_r",
			"xlights_glass_g",
			"xlights_glass_b",
			"xlights_glass_y"
		};
		hiddenSelectionsTextures[] =
		{
			"dz\gear\camping\data\tent_door_co.paa",
			"",
			"ZenTentBags\data\textures\bagpack_grey_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"dz\gear\camping\data\tent_door.rvmat",
			"dz\gear\camping\data\large_tent.rvmat",
			"dz\gear\camping\data\bagpack.rvmat"
		};
		openable = 0;
		carveNavmesh = 1;
		weight = 2000;
		itemSize[] = { 10,4 };
		itemsCargoSize[] = { 0,0 };
		//itemBehaviour = 0; // Setting this to 0 means you can't sprint with the bag in your hands. The tent's weight is added to the bag which drains stamina and is enough
		lootCategory = "Tents";
		repairableWithKits[] = { 5,2 };
		repairCosts[] = { 30,25 };
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "";
				description = "";
				attachmentSlots[] =
				{
					"ZenTentAttachment",
					"CookingTripod",
					"CamoNet"
				};
				icon = "set:dayz_inventory image:cookingtripod";
			}
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] =
					{

						{
							1,

							{
								""
							}
						},

						{
							0.69999999,

							{
								""
							}
						},

						{
							0.5,

							{
								""
							}
						},

						{
							0.30000001,

							{
								""
							}
						},

						{
							0,

							{
								""
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.050000001;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.30000001;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.5;
						healthLevels[] =
						{

							{
								1,

								{
									"dz\gear\camping\Data\tent_pristine_co.paa",
									"DZ\gear\camping\data\bagpack.rvmat"
								}
							},

							{
								0.69999999,

								{
									"dz\gear\camping\data\tent_worn_co.paa",
									"DZ\gear\camping\data\bagpack.rvmat"
								}
							},

							{
								0.5,

								{
									"dz\gear\camping\data\tent_damage_co.paa",
									"DZ\gear\camping\data\bagpack_damage.rvmat"
								}
							},

							{
								0.30000001,

								{
									"dz\gear\camping\data\tent_destruct_co.paa",
									"DZ\gear\camping\data\bagpack_damage.rvmat"
								}
							},

							{
								0,

								{
									"dz\gear\camping\data\tent_destruct_co.paa",
									"DZ\gear\camping\data\bagpack_destruct.rvmat"
								}
							}
						};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.050000001;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.30000001;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] =
					{
						"body"
					};
					transferToZonesNames[] =
					{
						"Inventory"
					};
					transferToZonesCoefs[] = { 1 };
					fatalInjuryCoef = -1;
				};
				class Inventory
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.5;
						healthLevels[] =
						{

							{
								1,

								{
									"DZ\gear\camping\data\bagpack.rvmat"
								}
							},

							{
								0.69999999,

								{
									"DZ\gear\camping\data\bagpack.rvmat"
								}
							},

							{
								0.5,

								{
									"DZ\gear\camping\data\bagpack_damage.rvmat"
								}
							},

							{
								0.30000001,

								{
									"DZ\gear\camping\data\bagpack_damage.rvmat"
								}
							},

							{
								0,

								{
									"DZ\gear\camping\data\bagpack_destruct.rvmat"
								}
							}
						};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.050000001;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.30000001;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] =
					{
						"inventory"
					};
					transferToZonesNames[] =
					{
						"Body",
						"Entrance",
						"Window1",
						"Window2",
						"Window3",
						"Window4",
						"Window5",
						"Window6",
						"Window7"
					};
					transferToZonesCoefs[] = { 1,1,1,1,1,1,1,1,1 };
					fatalInjuryCoef = -1;
				};
				class Entrance
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
						healthLevels[] =
						{

							{
								1,

								{
									"DZ\gear\camping\data\tent_door.rvmat",
									"DZ\gear\camping\data\tent_pristine_co.paa"
								}
							},

							{
								0.69999999,

								{
									"DZ\gear\camping\data\tent_door.rvmat",
									"DZ\gear\camping\data\tent_worn_co.paa"
								}
							},

							{
								0.5,

								{
									"DZ\gear\camping\data\tent_door_damage.rvmat",
									"DZ\gear\camping\data\tent_damage_co.paa"
								}
							},

							{
								0.30000001,

								{
									"DZ\gear\camping\data\tent_door_damage.rvmat",
									"DZ\gear\camping\data\tent_destruct_co.paa"
								}
							},

							{
								0,

								{
									"DZ\gear\camping\data\tent_door.rvmat",
									"DZ\gear\camping\data\tent_ruined_ca.paa"
								}
							}
						};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 5;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 40;
							};
						};
					};
					displayName = "$STR_CfgVehicles_Tent_Entrance0";
					componentNames[] =
					{
						"entranceo",
						"entrancec"
					};
					fatalInjuryCoef = -1;
				};
				class Window_Base
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
						healthLevels[] =
						{

							{
								1,

								{
									"DZ\gear\camping\data\tent_pristine_co.paa"
								}
							},

							{
								0.69999999,

								{
									"DZ\gear\camping\data\tent_worn_co.paa"
								}
							},

							{
								0.5,

								{
									"DZ\gear\camping\data\tent_damage_co.paa"
								}
							},

							{
								0.30000001,

								{
									"DZ\gear\camping\data\tent_destruct_co.paa"
								}
							},

							{
								0,

								{
									"DZ\gear\camping\data\tent_ruined_ca.paa"
								}
							}
						};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 5;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 40;
							};
						};
					};
					displayName = "$STR_CfgVehicles_LargeTent_Window0";
					componentNames[] =
					{
						""
					};
					fatalInjuryCoef = -1;
				};
				class Window1 : Window_Base
				{
					componentNames[] =
					{
						"window1o",
						"window1c"
					};
				};
				class Window2 : Window_Base
				{
					componentNames[] =
					{
						"window2o",
						"window2c"
					};
				};
				class Window3 : Window_Base
				{
					componentNames[] =
					{
						"window3o",
						"window3c"
					};
				};
				class Window4 : Window_Base
				{
					componentNames[] =
					{
						"window4o",
						"window4c"
					};
				};
				class Window5 : Window_Base
				{
					componentNames[] =
					{
						"window5o",
						"window5c"
					};
				};
				class Window6 : Window_Base
				{
					componentNames[] =
					{
						"window6o",
						"window6c"
					};
				};
				class Window7 : Window_Base
				{
					componentNames[] =
					{
						"window7o",
						"window7c"
					};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = { 1,1,1,0.050000001 };
				ambient[] = { 0.0099999998,0.0099999998,0.0099999998,0.0099999998 };
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0;
				heatHazePower = 0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class EntranceO
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class EntranceC
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window1O
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window2O
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window3O
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window4O
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window5O
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window6O
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window7O
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window1C
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window2C
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window3C
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window4C
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window5C
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window6C
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Window7C
			{
				source = "user";
				animPeriod = 0.0099999998;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.0099999998;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement_walk
				{
					soundSet = "mediumtent_movement_walk_SoundSet";
					id = 1;
				};
				class movement_run
				{
					soundSet = "mediumtent_movement_run_SoundSet";
					id = 3;
				};
				class movement_sprint
				{
					soundSet = "mediumtent_movement_sprint_SoundSet";
					id = 5;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
				class mediumtent_drop
				{
					soundset = "mediumtent_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class TentBag_Camo : TentBag
	{
		hiddenSelectionsTextures[] =
		{
			"dz\gear\camping\data\tent_door_co.paa",
			"",
			"ZenTentBags\data\textures\bagpack_camo_co.paa"
		};
	};
	class TentBag_Arctic : TentBag
	{
		hiddenSelectionsTextures[] =
		{
			"dz\gear\camping\data\tent_door_co.paa",
			"",
			"ZenTentBags\data\textures\bagpack_arctic_co.paa"
		};
	};
	class TentBag_Desert : TentBag
	{
		hiddenSelectionsTextures[] =
		{
			"dz\gear\camping\data\tent_door_co.paa",
			"",
			"ZenTentBags\data\textures\bagpack_desert_co.paa"
		};
	};
	class TentBag_Orel : TentBag
	{
		hiddenSelectionsTextures[] =
		{
			"dz\gear\camping\data\tent_door_co.paa",
			"",
			"ZenTentBags\data\textures\bagpack_orel_co.paa"
		};
	};

	// Define attachable tents that have no attachments or cargo (purely for visual purposes only to display what tent is attached to the backpack)
	// For whatever reason, when I attach an actual tent to the backpack the backpack displays the tent's cargo no matter how many ways I try to hide it
	class LargeTent : TentBase
	{
		attachments[] +=
		{
			"ZenTentBag"
		};
		class GUIInventoryAttachmentsProps
		{
			class TentBag
			{
				name = "$STR_ZEN_TENTBAG0";
				description = "$STR_ZEN_TENTBAG0";
				attachmentSlots[] =
				{
					"ZenTentBag"
				};
				icon = "default";
			}
		};
	};
	class LargeTent_Attached : LargeTent
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	}

	// Medium tents
	class MediumTent : TentBase
	{
		attachments[] +=
		{
			"ZenTentBag"
		};
		class GUIInventoryAttachmentsProps
		{
			class TentBag
			{
				name = "$STR_ZEN_TENTBAG0";
				description = "$STR_ZEN_TENTBAG0";
				attachmentSlots[] =
				{
					"ZenTentBag"
				};
				icon = "default";
			}
		};
	};
	class MediumTent_Attached : MediumTent
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	}
	class MediumTent_Green;
	class MediumTent_Green_Attached : MediumTent_Green
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	};
	class MediumTent_Orange;
	class MediumTent_Orange_Attached : MediumTent_Orange
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	};

	// Party tents
	class PartyTent : TentBase
	{
		attachments[] +=
		{
			"ZenTentBag"
		};
		class GUIInventoryAttachmentsProps
		{
			class TentBag
			{
				name = "$STR_ZEN_TENTBAG0";
				description = "$STR_ZEN_TENTBAG0";
				attachmentSlots[] =
				{
					"ZenTentBag"
				};
				icon = "default";
			}
		};
	};
	class PartyTent_Attached : PartyTent
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	};
	class PartyTent_Blue;
	class PartyTent_Blue_Attached : PartyTent_Blue
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	};
	class PartyTent_Brown;
	class PartyTent_Brown_Attached : PartyTent_Brown
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	};
	class PartyTent_Lunapark;
	class PartyTent_Lunapark_Attached : PartyTent_Lunapark
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	};

	// Car tent
	class CarTent : TentBase
	{
		attachments[] +=
		{
			"ZenTentBag"
		};
		class GUIInventoryAttachmentsProps
		{
			class TentBag
			{
				name = "$STR_ZEN_TENTBAG0";
				description = "$STR_ZEN_TENTBAG0";
				attachmentSlots[] =
				{
					"ZenTentBag"
				};
				icon = "default";
			}
		};
	};
	class CarTent_Attached : CarTent
	{
		itemsCargoSize[] = { 0,0 };
		attachments[] = {};
		inventorySlot[] += { "ZenTentAttachment" };
	};
};

class CfgSlots
{
	class Slot_ZenTentAttachment
	{
		name = "ZenTentAttachment";
		displayName = "";
		ghostIcon = "default";
	};

	class Slot_ZenTentBag
	{
		name = "ZenTentBag";
		displayName = "$STR_ZEN_TENTBAG0";
		ghostIcon = "back";
	};
};
