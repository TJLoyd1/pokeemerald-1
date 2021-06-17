.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_MaysHouse_1F_MapScripts:: @ 81F88A5
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_1F_OnLoad: @ 81F88B5
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes:: @ 81F88CA
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
	return

LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual:: @ 81F88DD
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F88EA
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
	return

LittlerootTown_MaysHouse_1F_OnTransition: @ 81F88F4
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs:: @ 81F8916
	setobjectxyperm LOCALID_MOM, 2, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV:: @ 81F8922
	setobjectxyperm LOCALID_MOM, 6, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor:: @ 81F892E
	setobjectxyperm LOCALID_MOM, 1, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
LittlerootTown_MaysHouse_1F_OnFrame: @ 81F893A
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1, LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F8964
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 1, 1
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs: @ 81F898A
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F898C
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, FEMALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport:: @ 81F899D
	lockall
	setvar VAR_0x8004, FEMALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	end

LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor:: @ 81F89AE
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach: @ 81F89EC
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RivalsHouse_1F_EventScript_RivalMom:: @ 81F89F3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_eq RivalsHouse_1F_EventScript_RivalTooBusy
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalTooBusy:: @ 81F8A1F
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalIsOnRoute103:: @ 81F8A29
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_GoHomeEverySoOften:: @ 81F8A33
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalSibling:: @ 81F8A3D
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom:: @ 81F8A4C
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, FEMALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival0:: @ 81F8A67
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival1:: @ 81F8A73
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival2:: @ 81F8A7F
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival:: @ 81F8A8B
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_ne LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay
	playbgm MUS_ENCOUNTER_MAY, TRUE
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay:: @ 81F8B2A
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0:: @ 81F8B35
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1:: @ 81F8B40
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2:: @ 81F8B4B
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0: @ 81F8B56
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1: @ 81F8B5E
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2: @ 81F8B62
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0:: @ 81F8B6A
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1:: @ 81F8B7C
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2:: @ 81F8B8E
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0: @ 81F8BA0
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1: @ 81F8BA4
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2: @ 81F8BAB
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0: @ 81F8BAF
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1: @ 81F8BB5
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2: @ 81F8BBF
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

RivalsHouse_1F_Text_OhYoureTheNewNeighbor: @ 81F8BC5
	.string "Oh, hello. And you are?\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Oh, you're {PLAYER}{KUN}, our new next-door\n"
	.string "neighbor! Hi!\p"
	.string "I have a {STR_VAR_1} about the same\n"
	.string "age as you.\p"
	.string "My {STR_VAR_1} was excited about making\n"
	.string "a new friend.\p"
	.string "My {STR_VAR_1} is upstairs, I think.$"

RivalsHouse_1F_Text_LikeChildLikeFather: @ 81F8CA5
	.string "I guess they really are related.\p"
	.string "My sister is as wild about POKéMON\n"
	.string "as my child.\p"
	.string "If she's not at her LAB, she's likely\n"
	.string "scrabbling about in grassy places.$"

RivalsHouse_1F_Text_TooBusyToNoticeVisit: @ 81F8D37
	.string "That {RIVAL}!\p"
	.string "I guess my child is too busy with\n"
	.string "POKéMON to notice that you came\l"
	.string "to visit, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_WentOutToRoute103: @ 81F8D93
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
	.string "just a little while ago.\p"
	.string "They really are related.\n"
	.string "{RIVAL} can't stay quietly at home.$"

RivalsHouse_1F_Text_ShouldGoHomeEverySoOften: @ 81F8E01
	.string "I think it's wonderful for people to\n"
	.string "travel with Pokémon.\p"
	.string "But you should go home every so often\n"
	.string "to let your mother know you're okay.\p"
	.string "She might not say it, but I'm sure she\n"
	.string "worries about you, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_MayWhoAreYou: @ 81F8EC6
	.string "wha?\n"
	.string "Who… Who are you?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Oh, you're {PLAYER}{KUN}.\n"
	.string "So your move was today.\p"
	.string "Um… I'm Lucy.\n"
	.string "Glad to meet you!\p"
	.string "I…\n"
	.string "I have this dream of filling my PokéDex\l"
	.string "with POKéMON all over the world.\p"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
	.string "my aunt, Prof. Acacia.\p"
	.string "I was hoping that you would be a,\n"
	.string "cool person {PLAYER}{KUN}, and that we could be friends.\p"
	.string "Oh, this is silly, isn't it?\n"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
	.string "Eheheh…\p"
	.string "Oh, no! I forgot!\p"
	.string "I was supposed to go help Acacia catch\n"
	.string "some wild POKéMON!\p"
	.string "{PLAYER}{KUN}, I'll catch you later!$"

RivalsHouse_1F_Text_BrendanWhoAreYou: @ 81F90B4
	.string "Hey!\n"
	.string "You…\p"
	.string "Who are you?\p"
	.string "Oh, you're {PLAYER}, aren't you?\n"
	.string "Moved in next door, right?\p"
	.string "I didn't know that you're a girl.\p"
	.string "My aunt, Prof. Acacia, said that our\n"
	.string "new next-door neighbor is a really cool\l"
	.string "kid, so I assumed you'd be a guy.\p"
	.string "My name's Roy.\n"
	.string "So, wassup, neighbor!\p"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
	.string "a POKéMON?\p"
	.string "Do you want me to go catch you one?\p"
	.string "Aw, darn, I forgot…\p"
	.string "I'm supposed to go help my aunt catch\n"
	.string "some wild POKéMON.\p"
	.string "Some other time, okay?$"

RivalsHouse_1F_Text_DoYouHavePokemon: @ 81F9262
	.string "Hi, neighbor!\p"
	.string "Do you already have your\n"
	.string "own POKéMON?$"

StarterTown_MayPlayersHouse_1F_EventScript_WatchingTVWithMom::
	lockall
	setvar VAR_MORNING_TALK, 1
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	checkplayergender
	compare VAR_RESULT MALE,
	goto_if_eq StarterTown_BrendanPlayersHouse_1F_EventScript_WatchingTVWithMom
	msgbox MayPlayersHouse_1F_Text_YoureUp, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, FemaleWalkTowardsPlayer
	waitmovement 0
	msgbox MayPlayersHouse_1F_Text_ComeWatchWithMe, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, FemaleWalkTowardsTable
	applymovement OBJ_EVENT_ID_PLAYER, FemaleWalkTowardsTableToo
	waitmovement 0
	msgbox MayPlayersHouse_1F_Text_TVTalks, MSGBOX_DEFAULT
	special StartWallClock
	goto StarterTown_MayPlayersHouse_1F_EventScript_VisitingTheRival
	releaseall
	end

StarterTown_BrendanPlayersHouse_1F_EventScript_WatchingTVWithMom::
	msgbox PlayersHouse_1F_Text_YoureUp, MSGBOX_DEFAULT
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox PlayersHouse_1F_Text_ResponseToYoureUp, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement LOCALID_MOM, MaleWalkTowardsPlayer
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ComeWatchWithMe, MSGBOX_DEFAULT
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox PlayersHouse_1F_Text_ResponseToComeWatchWithMe, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement LOCALID_MOM, MaleWalkTowardsTable
	applymovement OBJ_EVENT_ID_PLAYER, MaleWalkTowardsTableToo
	waitmovement 0
	msgbox PlayersHouse_1F_Text_TVTalks, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_ResponseToTVTalks, MSGBOX_DEFAULT
	special StartWallClock
	goto StarterTown_BrendanPlayersHouse_1F_EventScript_VisitingTheRival
	releaseall
	end

StarterTown_BrendanPlayersHouse_1F_EventScript_VisitingTheRival::
	lockall
	msgbox PlayersHouse_1F_Text_ForgotToTell, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, MaleWalkTowardsDoor
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PlayersHouse_1F_Text_Wait, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomWalksToGiveMaleRunningShoes
	waitmovement 0
	msgbox PlayersHouse_1F_Text_RunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PlayersHouse_1F_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox PlayersHouse_1F_Text_SeeYouLater
	releaseall
	end

StarterTown_MayPlayersHouse_1F_EventScript_VisitingTheRival::
	lockall
	msgbox MayPlayersHouse_1F_Text_ForgotToTell, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FemaleWalkTowardsDoor
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MayPlayersHouse_1F_Text_Wait, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomWalksToGiveRunningShoes
	waitmovement 0
	msgbox MayPlayersHouse_1F_Text_RunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message MayPlayersHouse_1F_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox MayPlayersHouse_1F_Text_SeeYouLater
	releaseall
	end

MaleWalkTowardsPlayer:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

MaleWalkTowardsTable:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_left
	step_end

MaleWalkTowardsTableToo:
	delay_16
	walk_down
	walk_right
	walk_down
	walk_right
	walk_right
	face_right
	step_end

MaleWalkTowardsDoor:
	face_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	delay_16
	delay_16
	face_up
	step_end

MomWalksToGiveMaleRunningShoes:
	face_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

FemaleWalkTowardsPlayer:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

FemaleWalkTowardsTable:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_left
	step_end

FemaleWalkTowardsTableToo:
	delay_16
	walk_down
	walk_right
	walk_down
	walk_right
	walk_right
	face_right
	step_end

FemaleWalkTowardsDoor:
	face_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	delay_16
	delay_16
	face_up
	step_end

MomWalksToGiveRunningShoes:
	face_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end


MayPlayersHouse_1F_Text_YoureUp:
	.string "Mom: Honey, It's nice to see you're up.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}Yea Mom, up with a very\n"
	.string "CRAZY morning.\p"
	.string "Mom: Aww Honey...$"

MayPlayersHouse_1F_Text_ComeWatchWithMe:
	.string "Mom: Come and watch TV with me to help\n"
	.string "ease your mind a bit.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}Sure, I guess a bit of TV will\n"
	.string "get my mind off everything.$"

MayPlayersHouse_1F_Text_TVTalks:
	.string "In Today's News, It seems that Team.....\p"
	.string "Mom: Why don't you go ahead and tell me\n"
	.string "what happened this morning huh?\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}So listen, what happened was...$"

MayPlayersHouse_1F_Text_ForgotToTell:
	.string "Mom:I forgot to mention that your friend\n"
	.string "wanted to see you for something.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}You mean {RIVAL}?\p"
	.string "Mom:Yes, you should go see what\n"
	.string "they wanted.$"

MayPlayersHouse_1F_Text_Wait:
	.string "Mom:WAIT!$"

MayPlayersHouse_1F_Text_RunningShoes:
	.string "Mom:You can't leave without these.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}Thanks Mom.$"

MayPlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

MayPlayersHouse_1F_Text_SeeYouLater:
	.string "Mom:See you later honey.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}Bye Mom.$"

PlayersHouse_1F_Text_YoureUp:
	.string "Mom: Honey, It's nice to see you're up.$"

PlayersHouse_1F_Text_ResponseToYoureUp:
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Just had a weird morning to start\n"
	.string "my day.\p"
	.string "Mom: Aww Honey...$"
	
PlayersHouse_1F_Text_ComeWatchWithMe:
	.string "Mom: Come and watch TV with me to help\n"
	.string "ease your mind a bit.$"
	

PlayersHouse_1F_Text_ResponseToComeWatchWithMe:
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Sure even though it won't get my\n"
	.string "mind off what happened at all.$"
PlayersHouse_1F_Text_TVTalks:
	.string "In Today's News, It seems that Team.....\p"
	.string "Mom: Why don't you go ahead and tell me\n"
	.string "what happened this morning huh?$"

PlayersHouse_1F_Text_ResponseToTVTalks:
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Uhh I guess what happened was...$"

PlayersHouse_1F_Text_ForgotToTell:
	.string "Mom:I forgot to mention that your friend\n"
	.string "wanted to see you for something.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Friend... you talking about {RIVAL}?\p"
	.string "Mom:Yes, you should go see what\n"
	.string "they wanted.$"

PlayersHouse_1F_Text_Wait:
	.string "Mom:WAIT!$"

PlayersHouse_1F_Text_RunningShoes:
	.string "Mom:You can't leave without these.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}How could forget about them.$"

PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

PlayersHouse_1F_Text_SeeYouLater:
	.string "Mom:See you later honey.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Yeah see ya.$"
