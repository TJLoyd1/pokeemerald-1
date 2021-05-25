.set LOCALID_TWIN, 1
.set LOCALID_MOM, 4
.set LOCALID_RIVAL, 7
.set LOCALID_BIRCH, 8

LittlerootTown_MapScripts:: @ 81E7DCB
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


LittlerootTown_OnTransition: @ 81E7DDB
	compare VAR_DOWNSTAIRS_DANGER, 1
	call_if_eq LittlerootTown_EventScript_RivalPosition
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGfxId
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	call_if_eq LittlerootTown_EventScript_MoveMomToMaysDoor
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	call_if_eq LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
	compare VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	call_if_eq LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	compare VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	call_if_eq LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	compare VAR_OLDALE_RIVAL_STATE, 1
	call_if_eq LittlerootTown_EventScript_MoveRivalFromOldale
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	call_if_eq LittlerootTown_EventScript_SetRivalLeftForRoute103
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	call_if_eq LittlerootTown_EventScript_HideMapNamePopup
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	call_if_eq LittlerootTown_EventScript_LeftLabAfterDexUpgrade
	end

LittlerootTown_EventScript_RivalPosition::
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_EventScript_MayRivalPosition
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setobjectxyperm 8, 4, 9
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setobjectxyperm 6, 17, 10
	return

LittlerootTown_EventScript_MayRivalPosition::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setobjectxyperm 9, 4, 9
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setobjectxyperm 6, 17, 10
	return	
	
LittlerootTown_EventScript_LeftLabAfterDexUpgrade:: @ 81E7E45
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_EventScript_HideMapNamePopup:: @ 81E7E4B
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_EventScript_SetRivalLeftForRoute103:: @ 81E7E4F
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

LittlerootTown_EventScript_MoveRivalFromOldale:: @ 81E7E53
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent:: @ 81E7E5C
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	return

LittlerootTown_EventScript_MoveMomToMaysDoor:: @ 81E7E67
	setobjectxyperm LOCALID_MOM, 14, 8
	return

LittlerootTown_EventScript_SetTwinPos:: @ 81E7E6F
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq LittlerootTown_EventScript_SetTwinGuardingRoutePos
	setobjectxyperm LOCALID_TWIN, 10, 1
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_EventScript_SetTwinGuardingRoutePos:: @ 81E7E86
	setobjectxyperm LOCALID_TWIN, 7, 4
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos:: @ 81E7E92
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorMale:: @ 81E7EB1
	setobjectxyperm LOCALID_MOM, 5, 9
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorFemale:: @ 81E7EB9
	setobjectxyperm LOCALID_MOM, 14, 9
	return

LittlerootTown_OnFrame: @ 81E7EC1
	map_script_2 VAR_DOWNSTAIRS_DANGER, 1, LittlerootTown_EventScript_Begin_Obsidian_Movement
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_EventScript_StepOffTruckMale:: @ 81E7EDB
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_StepOffTruckFemale:: @ 81E7EF9
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 255, 2, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_GoInsideWithMom:: @ 81E7F17
	delay 15
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
	waitmovement 0
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_Movement_MomExitHouse: @ 81E7F98
	walk_down
	step_end

LittlerootTown_Movement_MomApproachPlayerAtTruck: @ 81E7F9A
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_Movement_MomApproachDoor: @ 81E7F9D
	delay_16
	delay_8
	walk_up
	step_end

LittlerootTown_Movement_MomEnterHouse: @ 81E7FA1
	walk_up
	set_invisible
	step_end

LittlerootTown_Movement_PlayerApproachDoor: @ 81E7FA4
	delay_16
	delay_8
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_PlayerEnterHouse: @ 81E7FA9
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_PlayerStepOffTruck: @ 81E7FAC
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene:: @ 81E7FB1
	lockall
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	releaseall
	end

LittlerootTown_OnWarp: @ 81E7FE2
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade:: @ 81E7FEC
	addobject LOCALID_BIRCH
	addobject LOCALID_RIVAL
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale:: @ 81E8004
	setobjectxy LOCALID_RIVAL, 6, 10
	setobjectxy LOCALID_BIRCH, 5, 10
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale:: @ 81E8013
	setobjectxy LOCALID_RIVAL, 13, 10
	setobjectxy LOCALID_BIRCH, 14, 10
	end

LittlerootTown_EventScript_FatMan:: @ 81E8022
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

LittlerootTown_EventScript_Boy:: @ 81E802B
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

LittlerootTown_EventScript_Twin:: @ 81E8034
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_ne LittlerootTown_EventScript_GoSaveBirch
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoSaveBirch:: @ 81E805D
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	release
	end

LittlerootTown_EventScript_YouSavedBirch:: @ 81E807A
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoodLuck:: @ 81E8087
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_NeedPokemonTriggerLeft:: @ 81E8091
	lockall
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
	waitmovement 0
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_DangerousWithoutPokemon:: @ 81E80AD
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_Movement_TwinApproachPlayerLeft: @ 81E80D1
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_down
	step_end

LittlerootTown_Movement_TwinPushPlayerFromRoute: @ 81E80DF
	walk_down
	step_end

LittlerootTown_Movement_TwinReturnLeft: @ 81E80E1
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_fastest_down
	step_end

LittlerootTown_Movement_PushPlayerBackFromRoute: @ 81E80EB
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LittlerootTown_EventScript_NeedPokemonTriggerRight:: @ 81E80EF
	lockall
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
	waitmovement 0
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
	waitmovement 0
	releaseall
	end

LittlerootTown_Movement_TwinApproachPlayerRight: @ 81E810B
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_down
	step_end

LittlerootTown_Movement_TwinReturnRight: @ 81E8118
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger:: @ 81E811F
	lockall
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	releaseall
	end

LittlerootTown_EventScript_TownSign:: @ 81E8151
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign:: @ 81E815A
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign:: @ 81E8163
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_PlayersHouseSignMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_BirchsHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_PlayersHouseSignMale:: @ 81E817D
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignFemale:: @ 81E8186
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_MaysHouseSign:: @ 81E818F
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_BirchsHouseSignMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_PlayersHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_BirchsHouseSignMale:: @ 81E81A9
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale:: @ 81E81B2
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_GiveRunningShoesTrigger0:: @ 81E81BB
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_MOM, 10, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1:: @ 81E81CE
	lockall
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_MOM, 11, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger2:: @ 81E81E1
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger3:: @ 81E81ED
	lockall
	setvar VAR_0x8008, 3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger4:: @ 81E81F9
	lockall
	setvar VAR_0x8008, 4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger5:: @ 81E8205
	lockall
	setvar VAR_0x8008, 5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger:: @ 81E8211
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_MomNoticePlayerMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_MomNoticePlayerFemale
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale
	call LittlerootTown_EventScript_GiveRunningShoes
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetHomeDoorCoordsMale:: @ 81E8281
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_SetHomeDoorCoordsFemale:: @ 81E828C
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_MomNoticePlayerMale:: @ 81E8297
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

LittlerootTown_EventScript_MomNoticePlayerFemale:: @ 81E82A2
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale:: @ 81E82AD
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale2
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale3
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale4
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale5
	return

LittlerootTown_EventScript_MomApproachPlayerFemale:: @ 81E82F0
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale2
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale3
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale4
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale5
	return

LittlerootTown_EventScript_MomApproachPlayer0:: @ 81E8333
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayer1:: @ 81E8348
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale2:: @ 81E835D
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale3:: @ 81E8372
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale4:: @ 81E8387
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale5:: @ 81E839C
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale2:: @ 81E83B1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale3:: @ 81E83C6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale4:: @ 81E83DB
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale5:: @ 81E83F0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
	waitmovement 0
	return

LittlerootTown_EventScript_MomReturnHomeMale:: @ 81E8405
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_MomReturnHome0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_MomReturnHome1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale2
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale3
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale4
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale5
	return

LittlerootTown_EventScript_MomReturnHomeFemale:: @ 81E8448
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_MomReturnHome0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_MomReturnHome1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale2
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale3
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale4
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale5
	return

LittlerootTown_EventScript_MomReturnHome0:: @ 81E848B
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
	waitmovement 0
	return

LittlerootTown_EventScript_MomReturnHome1:: @ 81E8496
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
	waitmovement 0
	return

LittlerootTown_EventScript_MomReturnHomeMale2:: @ 81E84A1
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale3:: @ 81E84C7
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale4:: @ 81E84ED
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale5:: @ 81E8513
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale2:: @ 81E8539
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale3:: @ 81E855F
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale4:: @ 81E8585
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale5:: @ 81E85AB
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_Movement_MomApproachPlayer0: @ 81E85D1
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayer1: @ 81E85D8
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayerMale2: @ 81E85DF
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale3: @ 81E85E4
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale4: @ 81E85EA
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale5: @ 81E85ED
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale2: @ 81E85F1
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale3: @ 81E85F5
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale4: @ 81E85F8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale5: @ 81E85FE
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomReturnHome0: @ 81E8603
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHome1: @ 81E8609
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHomeMale2: @ 81E860F
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale3: @ 81E8615
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale4: @ 81E861C
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale5: @ 81E8620
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale2: @ 81E8625
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale3: @ 81E862A
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale4: @ 81E862E
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale5: @ 81E8635
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_MomExitThroughDoor: @ 81E863B
	walk_up
	step_end

LittlerootTown_EventScript_Mom:: @ 81E863D
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsMale
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call LittlerootTown_EventScript_GiveRunningShoes
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetReceivedRunningShoes:: @ 81E8686
	removeobject LOCALID_MOM
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end

LittlerootTown_EventScript_GiveRunningShoes:: @ 81E8693
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_Text_OurNewHomeLetsGoInside: @ 81E86BC
	.string "MOM: {PLAYER}, we're here, honey!\p"
	.string "It must be tiring riding with our things\n"
	.string "in the moving truck.\p"
	.string "Well, this is Littleroot Town.\p"
	.string "How do you like it?\n"
	.string "This is our new home!\p"
	.string "It has a quaint feel, but it seems to be\n"
	.string "an easy place to live, don't you think?\p"
	.string "And, you get your own room, {PLAYER}!\n"
	.string "Let's go inside.$"

LittlerootTown_Text_WaitPlayer: @ 81E87E1
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes: @ 81E87F0
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "introduce yourself to Prof. Acacia?\p"
	.string "Oh! What an adorable Pokémon!\n"
	.string "You got it from Prof. Acacia. How nice!\p"
	.string "You really are my child, all right.\n"
	.string "You look good together with Pokémon!\p"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, wear these Running Shoes.\p"
	.string "They'll put a zip in your step!$"

LittlerootTown_Text_SwitchShoesWithRunningShoes: @ 81E8925
	.string "{PLAYER} switched shoes with the\n"
	.string "Running Shoes.$"

LittlerootTown_Text_ExplainRunningShoes: @ 81E894F
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "Running Shoes to get that speed boost!\p"
	.string "“Slip on these Running Shoes and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens: @ 81E8A03
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "Pokémon now…\l"
	.string "I'm so happy for you honey.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems: @ 81E8ACF
	.string "If you use a PC, you can store items\n"
	.string "and Pokémon.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab: @ 81E8B25
	.string "Prof. Acacia spends days in her Lab\n"
	.string "studying, then she'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does Prof. Acacia spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut: @ 81E8BB8
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild Pokémon will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon: @ 81E8C07
	.string "It's dangerous if you don't have\n"
	.string "your own Pokémon.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening: @ 81E8C3A
	.string "Um, hi!\p"
	.string "There are scary Pokémon outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any Pokémon…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch: @ 81E8CE3
	.string "You saved Prof. Acacia!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon: @ 81E8D07
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign: @ 81E8D32
	.string "Littleroot Town\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab: @ 81E8D69
	.string "PROF. Acacia's Pokémon Lab$"

LittlerootTown_Text_PlayersHouse: @ 81E8D83
	.string "{PLAYER}'s House$"

LittlerootTown_Text_ProfBirchsHouse: @ 81E8D8E
	.string "Prof. Acacia'S House$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab: @ 81E8DA2
	.string "Prof. Acacia: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the Pokédex\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my Lab.$"

LittlerootTown_EventScript_Rivals_Mom::
	setvar VAR_TEMP_0, 1
	setflag FLAG_TIME_FOR_CHAOS
	setvar VAR_GOOD_MORNING, 1
	removeobject 1, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	showobjectat 2, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	end

LittlerootTown_EventScript_Begin_Obsidian_Movement::
	setrespawn 2
	setflag FLAG_ADVENTURE_STARTED
	playbgm MUS_ENCOUNTER_MAGMA, 1
	addobject LOCALID_MAXIE
	removeobject 10
	addobject 11
	addobject 12
	addobject 13
	addobject 14
	addobject 15
	addobject 16
	addobject 17
	addobject 18
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_EventScript_MaleBegin_Obsidian_Movement
	applymovement 7, Movement_To_Middle_Littleroot
	applymovement 11, Movement_With_Rhyos
	applymovement 12, Movement_With_Rhyos
	applymovement 13, Movement_With_Rhyos
	applymovement 14, Movement_With_Rhyos
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Headed_To_Speech
	applymovement 8, Rival_Headed_To_Speech
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_One, MSGBOX_DEFAULT
	applymovement 7, During_Speech_Move_Left
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_Two, MSGBOX_DEFAULT
	applymovement 7, During_Speech_Move_Right
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Prepare_to_Show_Pokemon, MSGBOX_DEFAULT
	applymovement 7, During_Speech_From_Right_To_Center
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Go_Claydol, MSGBOX_DEFAULT
	closemessage
	delay 40
	fadescreen 3
	addobject 10
	fadescreen 2
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_Three, MSGBOX_DEFAULT
	closemessage
	delay 40
	delay 40
	playse SE_ORB
	special DoOrbEffect
	fadescreen 3
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	fadescreen 2
	special FadeOutOrbEffect
	fadescreen 3
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	fadescreen 2
	waitstate
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_Four, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	waitse
	fadescreen 1
	removeobject 15
	removeobject 16
	removeobject 17
	removeobject 18
	fadescreen 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Claydol_Return
	closemessage
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	fadescreen 3
	removeobject 10
	fadescreen 2
	applymovement 7, Rhyos_Heads_To_Player_Rival
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_End, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Rhyos_Face_Up
	msgbox LittlerootTown_Text_Rhyos_Obisidian_Moveout, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Rhyos_Leaving
	applymovement 11, Grunt1_Leaving
	applymovement 12, Grunt2_Leaving
	applymovement 13, Grunt3_Leaving
	applymovement 14, Grunt4_Leaving
	waitmovement 0
	fadescreen 1
	removeobject 7
	removeobject 11
	removeobject 12
	removeobject 13
	removeobject 14
	fadescreen 0
	playbgm MUS_GSC_ROUTE38, 1
	applymovement 8, Face_Player_Direction
	msgbox LittlerootTown_Text_ThatWasWeird, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	applymovement 8, Rival_Headed_Home
	applymovement OBJ_EVENT_ID_PLAYER, Look_At_Rival
	waitmovement 0
	msgbox LittlerootTown_Text_ProfHoldup, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	showobjectat 6, MAP_LITTLEROOT_TOWN 
	applymovement 8, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Rival_Interrupted_Walk
	applymovement OBJ_EVENT_ID_PLAYER, Player_Hears_Prof
	waitmovement 0
	applymovement 6, Prof_Walk_To_Player_Rival
	waitmovement 0
	msgbox LittlerootTown_Text_Birch_Gives_Starter_Pokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	special ChooseStarter
	bufferleadmonspeciesname 0
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_Text_BirchUsesZigzagoons, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartProfessorBattleMaleRivalMudkip
	case 1, LittlerootTown_EventScript_StartProfessorBattleMaleRivalTorchic
	case 2, LittlerootTown_EventScript_StartProfessorBattleMaleRivalTreecko
	end

LittlerootTown_EventScript_StartProfessorBattleMaleRivalMudkip::
	multi_fixed_2_vs_1 TRAINER_PROF_BIRCH, LittlerootTown_Text_ProfMay_Defeat, TRAINER_LITTLEROOTTOWN_ROY_MUDKIP, TRAINER_BACK_PIC_BRENDAN
	special HealPlayerParty
	msgbox LittlerootTown_Text_AfterProfMayBattle, MSGBOX_DEFAULT
	closemessage
	msgbox LittlerootTown_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_Text_GoodLuck, MSGBOX_DEFAULT
	fadescreen 1
	removeobject 6
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	setflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	msgbox LittlerootTown_Text_How_She_Know_Names, MSGBOX_DEFAULT
	applymovement 8, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	msgbox Littleroot_Town_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartBrendanBattleTreecko
	case 1, LittlerootTown_EventScript_StartBrendanBattleTorchic
	case 2, LittlerootTown_EventScript_StartBrendanBattleMudkip
	end

LittlerootTown_EventScript_StartProfessorBattleMaleRivalTorchic::
	multi_fixed_2_vs_1 TRAINER_PROF_BIRCH, LittlerootTown_Text_ProfMay_Defeat, TRAINER_LITTLEROOTTOWN_ROY_TORCHIC, TRAINER_BACK_PIC_BRENDAN
	special HealPlayerParty
	msgbox LittlerootTown_Text_AfterProfMayBattle, MSGBOX_DEFAULT
	closemessage
	msgbox LittlerootTown_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_Text_GoodLuck, MSGBOX_DEFAULT
	fadescreen 1
	removeobject 6
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	setflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	msgbox LittlerootTown_Text_How_She_Know_Names, MSGBOX_DEFAULT
	applymovement 8, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	msgbox Littleroot_Town_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartBrendanBattleTreecko
	case 1, LittlerootTown_EventScript_StartBrendanBattleTorchic
	case 2, LittlerootTown_EventScript_StartBrendanBattleMudkip
	end

LittlerootTown_EventScript_StartProfessorBattleMaleRivalTreecko::
	multi_fixed_2_vs_1 TRAINER_PROF_BIRCH, LittlerootTown_Text_ProfMay_Defeat, TRAINER_LITTLEROOTTOWN_ROY_TREECKO, TRAINER_BACK_PIC_BRENDAN
	special HealPlayerParty
	msgbox LittlerootTown_Text_AfterProfMayBattle, MSGBOX_DEFAULT
	closemessage
	msgbox LittlerootTown_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_Text_GoodLuck, MSGBOX_DEFAULT
	fadescreen 1
	removeobject 6
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	setflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	msgbox LittlerootTown_Text_How_She_Know_Names, MSGBOX_DEFAULT
	applymovement 8, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	msgbox Littleroot_Town_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartBrendanBattleTreecko
	case 1, LittlerootTown_EventScript_StartBrendanBattleTorchic
	case 2, LittlerootTown_EventScript_StartBrendanBattleMudkip
	end

LittlerootTown_EventScript_StartBrendanBattleTreecko:: @ 81EC4BE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto LittlerootTown_EventScript_AfterBrendanBattle
	end

LittlerootTown_EventScript_StartBrendanBattleTorchic:: @ 81EC4CE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto LittlerootTown_EventScript_AfterBrendanBattle
	end

LittlerootTown_EventScript_StartBrendanBattleMudkip:: @ 81EC4DE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto LittlerootTown_EventScript_AfterBrendanBattle
	end

LittlerootTown_EventScript_AfterBrendanBattle:: @ 81EC4FC
	msgbox LittlerootTown_Text_BrendanTimeToHeadOut, MSGBOX_DEFAULT
	applymovement 8 ,Rival_Headed_To_Route_101
	waitmovement 0
	removeobject 8
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setvar VAR_DOWNSTAIRS_DANGER, 2
	setflag FLAG_RESCUED_BIRCH
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_Text_GoodLuck, MSGBOX_DEFAULT
	fadescreen 1
	removeobject 6
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_EventScript_MaleNicknameStarter
	msgbox LittlerootTown_Text_How_She_Know_Names, MSGBOX_DEFAULT
	applymovement 8, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	msgbox Littleroot_Town_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartBrendanBattleTreecko
	case 1, LittlerootTown_EventScript_StartBrendanBattleTorchic
	case 2, LittlerootTown_EventScript_StartBrendanBattleMudkip
	end

LittlerootTown_EventScript_MaleBegin_Obsidian_Movement::
	applymovement 7, Movement_To_Middle_Littleroot
	applymovement 11, Movement_With_Rhyos
	applymovement 12, Movement_With_Rhyos
	applymovement 13, Movement_With_Rhyos
	applymovement 14, Movement_With_Rhyos
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Headed_To_Speech
	applymovement 9, Rival_Headed_To_Speech
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_One, MSGBOX_DEFAULT
	applymovement 7, During_Speech_Move_Left
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_Two, MSGBOX_DEFAULT
	applymovement 7, During_Speech_Move_Right
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Prepare_to_Show_Pokemon, MSGBOX_DEFAULT
	applymovement 7, During_Speech_From_Right_To_Center
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Go_Claydol, MSGBOX_DEFAULT
	closemessage
	delay 40
	fadescreen 3
	addobject 10
	fadescreen 2
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_Three, MSGBOX_DEFAULT
	closemessage
	delay 40
	delay 40
	playse SE_ORB
	special DoOrbEffect
	fadescreen 3
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	fadescreen 2
	special FadeOutOrbEffect
	fadescreen 3
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	fadescreen 2
	waitstate
	msgbox LittlerootTown_Text_Rhyos_Speech_Part_Four, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	waitse
	fadescreen 1
	removeobject 15
	removeobject 16
	removeobject 17
	removeobject 18
	fadescreen 0
	msgbox LittlerootTown_Text_Rhyos_Speech_Claydol_Return
	closemessage
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	fadescreen 3
	removeobject 10
	fadescreen 2
	applymovement 7, Rhyos_Heads_To_Player_Rival
	waitmovement 0
	msgbox LittlerootTown_Text_Rhyos_Speech_End, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Rhyos_Face_Up
	msgbox LittlerootTown_Text_Rhyos_Obisidian_Moveout, MSGBOX_DEFAULT
	closemessage
	applymovement 7, Rhyos_Leaving
	applymovement 11, Grunt1_Leaving
	applymovement 12, Grunt2_Leaving
	applymovement 13, Grunt3_Leaving
	applymovement 14, Grunt4_Leaving
	waitmovement 0
	fadescreen 1
	removeobject 7
	removeobject 11
	removeobject 12
	removeobject 13
	removeobject 14
	fadescreen 0
	playbgm MUS_GSC_ROUTE38, 1
	applymovement OBJ_EVENT_ID_PLAYER, Face_May_Rival
	applymovement 9, Face_Player_Direction
	msgbox LittlerootTown_Text_MayThatWasWeird, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	applymovement 9, Rival_Headed_Home
	applymovement OBJ_EVENT_ID_PLAYER, Look_At_Rival
	waitmovement 0
	msgbox LittlerootTown_Text_ProfHoldup, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	showobjectat 6, MAP_LITTLEROOT_TOWN 
	applymovement 9, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Rival_Interrupted_Walk
	applymovement OBJ_EVENT_ID_PLAYER, Player_Hears_Prof
	waitmovement 0
	applymovement 6, Prof_Walk_To_Player_Rival
	waitmovement 0
	msgbox LittlerootTown_Text_Birch_Gives_Starter_Pokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	special ChooseStarter
	bufferleadmonspeciesname 0
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_Text_BirchUsesZigzagoons, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartProfessorBattleFemaleRivalMudkip
	case 1, LittlerootTown_EventScript_StartProfessorBattleFemaleRivalTorchic
	case 2, LittlerootTown_EventScript_StartProfessorBattleFemaleRivalTreecko
	end

LittlerootTown_EventScript_StartProfessorBattleFemaleRivalMudkip::
	multi_fixed_2_vs_1 TRAINER_PROF_BIRCH, LittlerootTown_Text_ProfMay_Defeat, TRAINER_MAY_ROUTE_103_TREECKO, TRAINER_BACK_PIC_MAY
	special HealPlayerParty
	msgbox LittlerootTown_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_Text_GoodLuck, MSGBOX_DEFAULT
	fadescreen 1
	removeobject 6
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	msgbox LittlerootTown_Text_MayHow_She_Know_Names, MSGBOX_DEFAULT
	applymovement 9, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_MAY, 1
	msgbox Littleroot_Town_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartMayBattleTreecko
	case 1, LittlerootTown_EventScript_StartMayBattleTorchic
	case 2, LittlerootTown_EventScript_StartMayBattleMudkip
	end

LittlerootTown_EventScript_StartProfessorBattleFemaleRivalTorchic::
	multi_fixed_2_vs_1 TRAINER_PROF_BIRCH, LittlerootTown_Text_ProfMay_Defeat, TRAINER_LITTLEROOTTOWN_LUCY_TORCHIC, TRAINER_BACK_PIC_MAY
	special HealPlayerParty
	msgbox LittlerootTown_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_Text_GoodLuck, MSGBOX_DEFAULT
	fadescreen 1
	removeobject 6
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	msgbox LittlerootTown_Text_MayHow_She_Know_Names, MSGBOX_DEFAULT
	applymovement 9, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_MAY, 1
	msgbox Littleroot_Town_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartMayBattleTreecko
	case 1, LittlerootTown_EventScript_StartMayBattleTorchic
	case 2, LittlerootTown_EventScript_StartMayBattleMudkip
	end

LittlerootTown_EventScript_StartProfessorBattleFemaleRivalTreecko::
	multi_fixed_2_vs_1 TRAINER_PROF_BIRCH, LittlerootTown_Text_ProfMay_Defeat, TRAINER_LITTLEROOTTOWN_LUCY_TREECKO, TRAINER_BACK_PIC_MAY
	special HealPlayerParty
	msgbox LittlerootTown_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	giveitem ITEM_POKE_BALL, 5
	msgbox LittlerootTown_Text_GoodLuck, MSGBOX_DEFAULT
	fadescreen 1
	removeobject 6
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	fadescreen 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement 9, Common_Movement_QuestionMark
	waitmovement 0
	msgbox LittlerootTown_Text_MayHow_She_Know_Names, MSGBOX_DEFAULT
	applymovement 9, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_MAY, 1
	msgbox Littleroot_Town_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartMayBattleTreecko
	case 1, LittlerootTown_EventScript_StartMayBattleTorchic
	case 2, LittlerootTown_EventScript_StartMayBattleMudkip
	end

LittlerootTown_EventScript_StartMayBattleTreecko:: @ 81EC48E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto LittlerootTown_EventScript_AfterMayBattle
	end

LittlerootTown_EventScript_StartMayBattleTorchic:: @ 81EC49E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto LittlerootTown_EventScript_AfterMayBattle
	end

LittlerootTown_EventScript_StartMayBattleMudkip:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto LittlerootTown_EventScript_AfterMayBattle
	end

LittlerootTown_EventScript_AfterMayBattle:: @ 81EC4FC
	msgbox LittlerootTown_Text_MayTimeToHeadOut, MSGBOX_DEFAULT
	applymovement 9 ,Rival_Headed_To_Route_101
	waitmovement 0
	removeobject 9
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setvar VAR_DOWNSTAIRS_DANGER, 2
	setflag FLAG_RESCUED_BIRCH
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_EventScript_MaleNicknameStarter::
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	msgbox LittlerootTown_Text_MayHow_She_Know_Names, MSGBOX_DEFAULT
	applymovement 9, Rival_Face_Player_Before_Battle
	applymovement OBJ_EVENT_ID_PLAYER, Player_Face_Rival_Before_Battle
	playbgm MUS_ENCOUNTER_MAY, 1
	msgbox Littleroot_Town_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LittlerootTown_EventScript_StartMayBattleTreecko
	case 1, LittlerootTown_EventScript_StartMayBattleTorchic
	case 2, LittlerootTown_EventScript_StartMayBattleMudkip
	end

Movement_To_Middle_Littleroot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	face_down
	step_end

Movement_With_Rhyos:
	walk_down
	walk_down
	walk_down
	step_end
	
Headed_To_Speech:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Rival_Headed_To_Speech:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	face_up
	step_end

During_Speech_Move_Left:
	walk_left
	walk_left
	face_down
	step_end

During_Speech_Move_Right:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

During_Speech_From_Right_To_Center:
	walk_left
	walk_left
	walk_down
	walk_right
	face_down
	step_end

Rhyos_Heads_To_Player_Rival:
	walk_down
	step_end
Rhyos_Face_Up:
	face_up
	step_end
	
Rhyos_Leaving:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	step_end
	
Grunt1_Leaving:
	walk_left
	walk_down
	walk_down
	walk_left
	face_up
	walk_up
	walk_up
	walk_up
	step_end
	
Grunt2_Leaving:
	walk_left
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end
	
Grunt3_Leaving:
	walk_right
	walk_right
	face_up
	delay_8
	walk_up
	walk_up
	step_end
	
Grunt4_Leaving:
	walk_right
	walk_right
	walk_down
	walk_right
	face_up
	walk_up
	walk_up
	walk_up
	step_end
	
Face_Player_Direction:
	face_left
	step_end
	
Face_May_Rival:
	face_right
	step_end
	
Rival_Headed_Home:
	walk_left
	walk_up
	walk_left
	step_end

Look_At_Rival:
	face_right
	delay_16
	face_up
	step_end

Player_Hears_Prof:
	face_right
	step_end

Rival_Interrupted_Walk:
	face_right
	step_end

Prof_Walk_To_Player_Rival:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_left
	step_end

Rival_Face_Player_Before_Battle:
	face_down
	step_end

Player_Face_Rival_Before_Battle:
	face_up
	step_end
	
Rival_Headed_To_Route_101:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

LittlerootTown_Text_Rhyos_Speech_Part_One:
	.string "Hello People of Littleroot Town.\n"
	.string "I am one of the many leaders of\l"
	.string "the government funded organization\p"
	.string "Obsidian.\p"
	.string "Like you all have probably heard on\n"
	.string "the news, we are applying the use\l"
	.string "science as well as Pokémon to create\p"
	.string "not only a better future for humans but\n"
	.string "Pokémon as well.$"

LittlerootTown_Text_Rhyos_Speech_Part_Two:
	.string "We of Obsidian are working hard so\n"
	.string "both Pokémon and humans can live in\l"
	.string "peace and harmony while Pokémon have\p"
	.string "freedom from being controlled by those\n"
	.string	"who use Pokémon for devilish incentives.\p"
	.string "Obsidian will strive to keep both\n"
	.string "Pokémon and humans unscathed!$"

LittlerootTown_Text_Rhyos_Speech_Prepare_to_Show_Pokemon:
	.string "I am now going to show you\n"
	.string "all something we have been\l"
	.string "operative on for some time now.$"

LittlerootTown_Text_Rhyos_Speech_Go_Claydol:
	.string "GO DUSCLOPS!$"

LittlerootTown_Text_Rhyos_Speech_Part_Three:
	.string "With this artificial Mega Stone that\n"
	.string "the scientists at Obsidian put their\l"
	.string "hard work into for years, this\p"
	.string "Dusclops, which usually doesn't mega\n"
	.string "evolve, will now do such as that.$"

LittlerootTown_Text_Rhyos_Speech_Part_Four:
	.string "It appears the Mega Stone still needs\n"
	.string "some fine tuning.\p"
	.string "However...\p"
	.string "This Mega Stone can sense when\n"
	.string "specific Pokémon feel threatened no\l"
	.string "matter the enviroment.\p"
	.string "They can now have the option to mega\n"
	.string "evolve with the only exception of being\l"
	.string "around people with an unthreatening\p"
	.string "presence because this stone can also\n"
	.string "sense the aggressiveness in a person.\p"
	.string "Once we perfect this artificial mega\n"
	.string "stone we will provide them in the wild\l"
	.string "all around the region.$"
	
LittlerootTown_Text_Rhyos_Speech_Claydol_Return:
	.string "DUSCLOPS RETURN!$"

LittlerootTown_Text_Rhyos_Speech_End:
	.string "I know that you two are working with\n"
	.string "Birch to stop our plans.\p"
	.string "As Team Obsidian Admin, Rhyos, I\n"
	.string "REFUSE to let that happen!$"

LittlerootTown_Text_Rhyos_Obisidian_Moveout:
	.string "TEAM OBSIDIAN!\p"
	.string "LET'S MOVE OUT!$"
	
LittlerootTown_Text_Rhyos_Speech:
	.string "Go Listen to Ugh in FNF Right Now!$"

LittlerootTown_Text_ThatWasWeird:
	.string "{RIVAL}:{COLOR BLUE}That was very 'educational' and\n"
	.string "especially fucking weird.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}Especially what happened to that\n"
	.string "poor Dusclops.\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR BLUE}Well I'm gonna head home and\n"
	.string "do more research about Professor May.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}Alright I'll see you later.$"

LittlerootTown_Text_MayThatWasWeird:
	.string "{PLAYER}:{COLOR BLUE}That was very 'educational' and\n"
	.string "especially fucking weird.\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR RED}Especially what happened to that\n"
	.string "poor Dusclops.\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR RED}Well I'm gonna head home and\n"
	.string "do more research about Professor May.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR BLUE}Alright see ya later.$"

LittlerootTown_Text_ProfHoldup:
	.string "PLEASE HOLD ON A SECOND!$"

LittlerootTown_Text_Birch_Gives_Starter_Pokemon:
	.string "Prof.May:Hello.\n"
	.string "I'm May, or as you've seen on the world\l"
	.string "wide web, Professor May Birch.\p"
	.string "I never would've expect them to find this\n"
	.string "place so I need you two to do me a favor.\p"
	.string "Take one of these Pokémon each and help\n"
	.string "stop this rotten-cored organization\l"
	.string "from hurting and experimenting on the\p"
	.string "Pokémon of the region.\p"
	.string "I'm also going to give you both a Pokédex\n"
	.string "and five Pokeballs to help start your\l"
	.string "journey.\p"
	.string "While adventuring this region to stop\n"
	.string "Team Obsidian in their tracks for a\l"
	.string "'better future', challenge the gym \p"
	.string "leaders and aim to become the\n"
	.string "CHAMPION and the best TRAINER around.\p"
	.string "Make the best of your journey as you\n"
	.string "stop Team Obsidian.$"

LittlerootTown_Text_BirchUsesZigzagoons:
	.string "To test both of your abilities I'm\n"
	.string "going to have you face off against\p"
	.string "these Zigzagoons.$"

LittlerootTown_Text_ProfMay_Defeat:
	.string "You guys make such a good team!$"
	
LittlerootTown_Text_AfterProfMayBattle:
	.string "I can see you both can make great\n"
	.string "choices while also working together.$"

LittlerootTown_Text_WhyNotGiveNicknameToMon:
	.string "Prof. May: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"

LittlerootTown_Text_ReceivedPokedex:
	.string "{PLAYER} received the POKéDEX!$"

LittlerootTown_Text_GoodLuck:
	.string "I wish the best of luck to you\n"
	.string "both {PLAYER} and {RIVAL}.$"

LittlerootTown_Text_How_She_Know_Names:
	.string "{PLAYER}:{COLOR RED}How did she know our name?\p"
	.string "{COLOR DARK_GREY}...\p"
	.string "{RIVAL}:{COLOR BLUE}I-I don't know.\n"
	.string "Well whatever.$"

Littleroot_Town_Text_BrendanLetsBattle:
	.string "{COLOR BLUE}You already know what's about to\n"
	.string "happen since we got our own Pokémon.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}It's time to BATTLE!$"

LittlerootTown_Text_BrendanTimeToHeadOut:
	.string "{RIVAL}:{COLOR BLUE}It's time we actually left and\n"
	.string "got to exporing the region.\l"
	.string "I'm going ahead.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}Yeah.$"

LittlerootTown_Text_MayHow_She_Know_Names:
	.string "{RIVAL}:{COLOR RED}How did she know our name?\p"
	.string "{COLOR DARK_GREY}...\p"
	.string "{PLAYER}:{COLOR BLUE}I-I don't know.\n"
	.string "Well whatever.$"

Littleroot_Town_Text_MayLetsBattle:
	.string "{RIVAL}:{COLOR RED}You already know what's about to\n"
	.string "happen since we got our own Pokémon.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR BLUE}It's time to BATTLE!$"

LittlerootTown_Text_MayTimeToHeadOut:
	.string "{RIVAL}:{COLOR RED}It's about time we're able leave\n"
	.string "and go explore the region.\l"
	.string "I'm going ahead.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR BLUE}Don't let me pass you up.$"

LittlerootTown_EventScript_GotoShinyCharm::
	goto_if_set FLAG_RECEIVED_POKEDEX_FROM_BIRCH, LittlerootTown_EventScript_MomGivesShinyCharm
	end
	
LittlerootTown_EventScript_GotoShinyCharm2::
	goto_if_set FLAG_RECEIVED_POKEDEX_FROM_BIRCH, LittlerootTown_EventScript_MomGivesShinyCharm2
	end

LittlerootTown_EventScript_MomGivesShinyCharm::
	lockall
	setvar VAR_RECEIVED_SHINY_CHARM, 1
	addobject  4
	msgbox LittlerootTown_Text_MomCallsPlayer, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FaceMom
	applymovement 4, MomWalksToPlayer
	waitmovement 0
	msgbox LittlerootTown_Text_MomGivesShinyCharm, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SHINY_CHARM
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_SYS_DETECTOR_MODE
	msgbox LittlerootTown_Text_SeeYouLaterHoney, MSGBOX_DEFAULT
	closemessage
	applymovement 4, MomWalksAway
	waitmovement 0
	removeobject 4
	releaseall
	end

LittlerootTown_EventScript_MomGivesShinyCharm2::
	lockall
	setvar VAR_RECEIVED_SHINY_CHARM, 1
	addobject  4
	msgbox LittlerootTown_Text_MomCallsPlayer, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FaceMom
	applymovement 4, MomWalksToPlayer2
	waitmovement 0
	msgbox LittlerootTown_Text_MomGivesShinyCharm, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SHINY_CHARM
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_SYS_DETECTOR_MODE
	msgbox LittlerootTown_Text_SeeYouLaterHoney, MSGBOX_DEFAULT
	closemessage
	applymovement 4, MomWalksAway
	waitmovement 0
	removeobject 4
	releaseall
	end
	
FaceMom:
	face_down
	step_end

MomWalksToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

MomWalksToPlayer2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end
	
MomWalksAway:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Text_MomCallsPlayer:
	.string "Mom: {PLAYER}!$"

LittlerootTown_Text_MomGivesShinyCharm:
	.string "Prof. May told me she has you going\n"
	.string "on a journey for her so I thought I\l"
	.string "should give you one last parting gift\p"
	.string "before you leave.$"

LittlerootTown_Text_ReceivedShinyCharm:
	.string "{PLAYER} received a Shiny Charm.$"

LittlerootTown_Text_SeeYouLaterHoney:
	.string "I'll see you later honey.\p"
	.string "Don't forget to visit home sometimes\n"
	.string "either.$"