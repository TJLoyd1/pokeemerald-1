.set LOCALID_RIVAL, 1

LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition: @ 81F83EE
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	call_if_lt LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	call_if_ge LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	call_if_eq PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos:: @ 81F841A
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
	compare VAR_BIRCH_LAB_STATE, 2
	goto_if_ge LittlerootTown_BrendansHouse_2F_EventScript_Ret
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos

LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos:: @ 81F8433
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Ret
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret  @ Odd that the MaysHouse equivalent was used here instead
	setobjectxyperm LOCALID_RIVAL, 0, 2
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_2F_EventScript_Ret:: @ 81F8456
	return

LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan:: @ 81F8457
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
	return

LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan:: @ 81F8464
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_OnWarp: @ 81F846A
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor:: @ 81F8474
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SecretBase_EventScript_InitDecorations
	end

LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall:: @ 81F8481
	lockall
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan:: @ 81F8497
	delay 10
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	compare VAR_FACING, DIR_NORTH
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
	compare VAR_FACING, DIR_SOUTH
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
	compare VAR_FACING, DIR_EAST
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth:: @ 81F8507
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth:: @ 81F8536
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest:: @ 81F8565
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast:: @ 81F8594
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters: @ 81F85BC
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth: @ 81F85C0
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth: @ 81F85C6
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth: @ 81F85CF
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth: @ 81F85D7
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth: @ 81F85DB
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth: @ 81F85E2
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest: @ 81F85E8
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest: @ 81F85ED
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest: @ 81F85F6
	delay_8
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast: @ 81F85FD
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast: @ 81F8604
	walk_up
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast: @ 81F8609
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_PC:: @ 81F860D
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC:: @ 81F8626
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F863F
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC:: @ 81F864C
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Notebook:: @ 81F8656
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

PlayersHouse_2F_EventScript_GameCube:: @ 81F865F
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayersHouse_2F_Text_ClockIsStopped: @ 81F8668
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom: @ 81F869A
	.string "Mom: {PLAYER}, how do you like your\n"
	.string "new room?\p"
	.string "Good! Everything's put away neatly!\p"
	.string "They finished moving everything in\n"
	.string "downstairs, too.\p"
	.string "Pokémon movers are so convenient!\p"
	.string "Oh, you should make sure that\n"
	.string "everything's all there on your desk.$"

PlayersHouse_2F_Text_Notebook: @ 81F877F
	.string "{PLAYER} flipped open the notebook.\p"
	.string "Adventure Rule No. 1\n"
	.string "Open the Menu with START.\p"
	.string "Adventure Rule No. 2\n"
	.string "Record your progress with Save.\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap: @ 81F8820
	.string "{PLAYER} took a closer look at the\n"
	.string "Hoenn region map.$"

PlayersHouse_2F_Text_ItsAGameCube: @ 81F884F
	.string "It's a Nintendo Switch.\p"
	.string "Super Smash Bros. Ultimate is\n"
	.string "playing on the screen.$"

StarterTown_PlayersHouse_2F_EventScript_WakeUp::
	lockall
	setvar VAR_WAKING_UP, 1
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq StarterTown_MayPlayersHouse_2F_EventScript_WakeUp
	removeobject 2, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	removeobject 4, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	msgbox PlayersHouse_2F_Text_WakeUp, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

StarterTown_RivalsHouse_2F_EventScript_OnSet::
	setvar VAR_BIG_COMMOTION, 1
	goto_if_set FLAG_GOOD_MORNING, StarterTown_RivalsHouse_2F_EventScript_Commotion
	end

StarterTown_RivalsHouse_2F_EventScript_Commotion::
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq StarterTown_MaleRivalsHouse_2F_EventScript_Commotion
	addobject 2
	removeobject 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	applymovement 2, Common_Movement_ExclamationMark
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	waitmovement 0
	applymovement 2, FaceRight
	msgbox StarterTown_RivalsHouse_2F_Text_RivalHey, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Headed_Towards_PC_With_Rival
	waitmovement 0
	msgbox StarterTown_RivalsHouse_2F_Text_RivalMentionsProf, MSGBOX_DEFAULT
	closemessage
	msgbox StarterTown_RivalsHouse_2F_Text_MomYells
	playbgm MUS_HELP, 1
	applymovement 2, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox StarterTown_RivalsHouse_2F_Text_Curiousity, MSGBOX_DEFAULT
	applymovement 2, Rival_Moves_Towards_Stairs
	applymovement OBJ_EVENT_ID_PLAYER, Player_Moves_Towards_Stairs
	waitmovement 0
	setvar VAR_DOWNSTAIRS_DANGER, 1
	setflag FLAG_DOWNSTAIRS_DANGER
	clearflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 3
	waitstate
	releaseall
	end

StarterTown_MaleRivalsHouse_2F_EventScript_Commotion::
	applymovement 3, Common_Movement_ExclamationMark
	playbgm MUS_ENCOUNTER_MAY, 1
	waitmovement 0
	applymovement 3, FaceRight
	msgbox StarterTown_MaleRivalsHouse_2F_Text_RivalHey, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Headed_Towards_PC_With_Rival
	waitmovement 0
	msgbox StarterTown_MaleRivalsHouse_2F_Text_RivalMentionsProf, MSGBOX_DEFAULT
	closemessage
	msgbox StarterTown_MaleRivalsHouse_2F_Text_MomYells
	playbgm MUS_HELP, 1
	applymovement 3, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox StarterTown_MaleRivalsHouse_2F_Text_Curiousity, MSGBOX_DEFAULT
	applymovement 3, Rival_Moves_Towards_Stairs
	applymovement OBJ_EVENT_ID_PLAYER, Player_Moves_Towards_Stairs
	waitmovement 0
	setvar VAR_DOWNSTAIRS_DANGER, 1
	setflag FLAG_DOWNSTAIRS_DANGER
	clearflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 3
	waitstate
	releaseall
	end

StarterTown_RivalsHouse_2F_EventScript_OnSetSouth::
	setvar VAR_BIG_COMMOTION, 1
	goto_if_set FLAG_GOOD_MORNING, StarterTown_RivalsHouse_2F_EventScript_CommotionSouth
	end

StarterTown_RivalsHouse_2F_EventScript_CommotionSouth::
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq StarterTown_MaleRivalsHouse_2F_EventScript_CommotionSouth
	addobject 2
	removeobject 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	applymovement 2, Common_Movement_ExclamationMark
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	waitmovement 0
	applymovement 2, FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceLeft
	waitmovement 0
	msgbox StarterTown_RivalsHouse_2F_Text_RivalHey, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Headed_Towards_PC_With_RivalSouth
	waitmovement 0
	msgbox StarterTown_RivalsHouse_2F_Text_RivalMentionsProf, MSGBOX_DEFAULT
	closemessage
	msgbox StarterTown_RivalsHouse_2F_Text_MomYells
	playbgm MUS_HELP, 1
	applymovement 2, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox StarterTown_RivalsHouse_2F_Text_Curiousity, MSGBOX_DEFAULT
	applymovement 2, Rival_Moves_Towards_Stairs
	applymovement OBJ_EVENT_ID_PLAYER, Player_Moves_Towards_Stairs
	waitmovement 0
	setvar VAR_DOWNSTAIRS_DANGER, 1
	setflag FLAG_DOWNSTAIRS_DANGER
	clearflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 3
	waitstate
	releaseall
	end

StarterTown_MaleRivalsHouse_2F_EventScript_CommotionSouth::
	applymovement 3, Common_Movement_ExclamationMark
	playbgm MUS_ENCOUNTER_MAY, 1
	waitmovement 0
	applymovement 3, FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFaceLeft
	waitmovement 0
	msgbox StarterTown_MaleRivalsHouse_2F_Text_RivalHey, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Headed_Towards_PC_With_RivalSouth
	waitmovement 0
	msgbox StarterTown_MaleRivalsHouse_2F_Text_RivalMentionsProf, MSGBOX_DEFAULT
	closemessage
	msgbox StarterTown_MaleRivalsHouse_2F_Text_MomYells
	playbgm MUS_HELP, 1
	applymovement 3, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox StarterTown_MaleRivalsHouse_2F_Text_Curiousity, MSGBOX_DEFAULT
	applymovement 3, Rival_Moves_Towards_Stairs
	applymovement OBJ_EVENT_ID_PLAYER, Player_Moves_Towards_Stairs
	waitmovement 0
	setvar VAR_DOWNSTAIRS_DANGER, 1
	setflag FLAG_DOWNSTAIRS_DANGER
	clearflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 3
	waitstate
	releaseall
	end
	
FaceRight:
	face_right
	step_end

PlayerFaceLeft:
	face_left
	step_end

Headed_Towards_PC_With_Rival:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Headed_Towards_PC_With_RivalSouth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	step_end


Rival_Moves_Towards_Stairs:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end
	
Player_Moves_Towards_Stairs:
	delay_16
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

PlayersHouse_2F_Text_WakeUp:
	.string "Mom:{PLAYER}.\n"
	.string "When you get up come downstairs.$"

StarterTown_RivalsHouse_2F_Text_RivalHey:
	.string "{RIVAL}:{COLOR BLUE}I see you made it.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}Yea, my mom told me you had\n"
	.string "to tell me something.\l"
	.string "It better be important.\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR BLUE}You gotta come here so I can\n"
	.string "show you how cool this shit is.$"

StarterTown_RivalsHouse_2F_Text_RivalMentionsProf:
	.string "{RIVAL}:{COLOR BLUE}So I found something on the\n"
	.string "internet about a professor named May\l"
	.string "who supposedly moved here two days ago\p"
	.string "because of 'research' reasons.\l"
	.string "Apparently she's giving away some\n"
	.string "Pokémon to new trainers like her\l"
	.string "father used to do.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}Does she have some kind of rare\n"
	.string "Pokémon or something?\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR BLUE}From what I read online, she\n"
	.string "has three 'unique' Pokémon that was\l"
	.string "aquired as she traveled across many\p"
	.string "different regions.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}I think we should go see her\n"
	.string "so we can get a Pokémon.\l"
	.string "It's about time we left the house.\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR BLUE}Yeah I totally agr-$"

StarterTown_RivalsHouse_2F_Text_MomYells:
	.string "KIDS GET DOWN HERE QUICK!!$"

StarterTown_RivalsHouse_2F_Text_Curiousity:
	.string "{RIVAL}:{COLOR BLUE}Let's go see what's going on.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}Okay let's go.$"

StarterTown_MaleRivalsHouse_2F_Text_RivalHey:
	.string "{RIVAL}:{COLOR RED}You finally made it.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR BLUE}I only came because you\n"
	.string "had to tell me something.\l"
	.string "It must be important?\p"
	.string "{COLOR DARK_GREY}May:{COLOR RED}You gotta come here so I can\n"
	.string "show you how amazing this is.$"

StarterTown_MaleRivalsHouse_2F_Text_RivalMentionsProf:
	.string "{RIVAL}:{COLOR RED}So I found something on the\n"
	.string "internet about a professor named May\l"
	.string "who supposedly moved here two days ago\p"
	.string "because of 'research' reasons.\l"
	.string "Apparently she's giving away some\n"
	.string "Pokémon to new trainers like her\l"
	.string "father used to do.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR BLUE}Does she have some kind of rare\n"
	.string "Pokémon or something?\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR RED}From what I read online, she\n"
	.string "has three 'unique' Pokémon that was\l"
	.string "aquired as she traveled across many\p"
	.string "different regions.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR BLUE}we should go see her then\n"
	.string "so we can get a Pokémon.\l"
	.string "It's about time we left the damn house.\p"
	.string "{COLOR DARK_GREY}{RIVAL}:{COLOR RED}Yeah I actually agr-$"

StarterTown_MaleRivalsHouse_2F_Text_MomYells:
	.string "KIDS GET DOWN HERE QUICK!!$"

StarterTown_MaleRivalsHouse_2F_Text_Curiousity:
	.string "{RIVAL}:{COLOR RED}Something happened.\n"
	.string "Let's Go.\p"
	.string "{COLOR DARK_GREY}{PLAYER}:{COLOR RED}Yeah Yeah.$"