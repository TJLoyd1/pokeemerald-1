.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_1F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes:: @ 81F777A
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:: @ 81F778D
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F779A
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
	return

LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
	compare VAR_DOWNSTAIRS_DANGER, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveRivalMomToTV
	compare VAR_DOWNSTAIRS_DANGER, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveRivalNexttoPlayer
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveRivalMomToTV::
	setobjectxyperm 2, 4, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveRivalNexttoPlayer::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMayRivalNexttoPlayer
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setobjectxyperm 4, 9, 3
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	return
LittlerootTown_BrendansHouse_1F_EventScript_MoveMayRivalNexttoPlayer::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setobjectxyperm 5, 9, 3
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	return 
	
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:: @ 81F77C6
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:: @ 81F77D2
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:: @ 81F77DE
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_OnWarp:
	map_script_2 VAR_DOWNSTAIRS_DANGER, 1, LittlerootTown_BrendansHouse_1F_EventScript_MoveRivalMomToTV
	map_script_2 VAR_DOWNSTAIRS_DANGER, 1, LittlerootTown_BrendansHouse_1F_EventScript_MoveRivalNexttoPlayer
	.2byte 0
@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
	map_script_2 VAR_DOWNSTAIRS_DANGER, 1, StarterTown_RivalsHouse_1F_EventScript_Downstairs_Danger
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs: @ 81F783A
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F783C
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport:: @ 81F784D
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor:: @ 81F785E
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach: @ 81F789C
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom:: @ 81F78A3
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0:: @ 81F78BE
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1:: @ 81F78CA
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2:: @ 81F78D6
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival:: @ 81F78E2
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
	call_if_ne LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan:: @ 81F7981
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0:: @ 81F798C
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1:: @ 81F7997
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2:: @ 81F79A2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0: @ 81F79AD
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1: @ 81F79B5
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2: @ 81F79B9
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0:: @ 81F79C1
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1:: @ 81F79D3
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2:: @ 81F79E5
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0: @ 81F79F7
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1: @ 81F79FB
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2: @ 81F7A02
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0: @ 81F7A06
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1: @ 81F7A0C
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

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2: @ 81F7A16
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere: @ 81F7A1C
	.string "Mom: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock: @ 81F7A46
	.string "The mover's Pokémon do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "I bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom: @ 81F7B24
	.string "Mom: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"

PlayersHouse_1F_Text_GoSetTheClock: @ 81F7B67
	.string "Mom: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

PlayersHouse_1F_Text_OhComeQuickly: @ 81F7B96
	.string "Mom: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn: @ 81F7BBC
	.string "MOM: Look! It's Petalburg Gym!\n"
	.string "Maybe Virgil will be on!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim: @ 81F7BF1
	.string "Mom: Oh… It's over.\p"
	.string "I think Virgil was on, but we missed him.\n"
	.string "Too bad.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor: @ 81F7C35
	.string "Oh, yes.\n"
	.string "One of my's friends lives in town.\p"
	.string "Prof. Acacia is her name.\p"
	.string "She lives right next door, so you should\n"
	.string "go over and introduce yourself.$"

PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
	.string "MOM: See you, honey!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
	.string "Mom: Did you introduce yourself to\n"
	.string "Prof. Acacia?$"

PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
	.string "Mom: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
	.string "Mom: Take care, honey!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom: @ 81F7D73
	.string "Mom: Oh? Did Virgil give you that BADGE?\p"
	.string "Then here's something from me!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard: @ 81F7DBE
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayersHouse_1F_Text_IsThatAPokenav: @ 81F7E0E
	.string "Mom: What is that, honey? A PokéNav?\n"
	.string "Someone from Devon gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom: @ 81F7E89
	.string "Registered Mom\n"
	.string "in the PokéNav.$"

PlayersHouse_1F_Text_Vigoroth1: @ 81F7EA8
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2: @ 81F7EB3
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym: @ 81F7EC6
	.string "Interviewer: …We brought you this\n"
	.string "report from in front of Petalburg Gym.$"

PlayersHouse_1F_Text_TheresAMovieOnTV: @ 81F7F0F
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_RunningShoesManual: @ 81F7F66
	.string "It's the instruction booklet for the\n"
	.string "Running Shoes.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your Running Shoes.\p"
	.string "“Lace up your Running Shoes and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou: @ 81F800E
	.string "Virgil: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But just know I haven't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "Mr. Briney.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove: @ 81F80FE
	.string "Virgil: Hm, a Ticket for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "Slateport and Lilycove.$"

PlayersHouse_1F_Text_BetterGetBackToGym: @ 81F815B
	.string "I'd better get back to Petalburg Gym.\p"
	.string "Mom, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger: @ 81F81B9
	.string "Mom: That Virgil…\p"
	.string "He comes by for the first time in a\n"
	.string "while, but all he talks about is Pokémon.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory: @ 81F824B
	.string "Mom: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash: @ 81F826F
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various Hoenn locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "Pokémon in flight.\p"
	.string "The identity of this Pokémon is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay: @ 81F8351
	.string "Mom: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that Pokémon was?$"

PlayersHouse_1F_Text_StillUnknownPokemon: @ 81F83A1
	.string "Mom: Well, isn't that something!\n"
	.string "There are still unknown Pokémon.$"

StarterTown_RivalsHouse_1F_EventScript_FlagSet::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_TIME_FOR_CHAOS, StarterTown_RivalsHouse_1F_EventScript_GoodMorning
	end

StarterTown_RivalsHouse_1F_EventScript_GoodMorning::
	lockall
	setflag FLAG_GOOD_MORNING
	applymovement OBJ_EVENT_ID_PLAYER,FaceLeft
	checkplayergender
	compare VAR_RESULT, MALE
	goto StarterTown_MaleRivalsHouse_1F_EventScript_GoodMorning
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	showobjectat 2, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	msgbox StarterTown_RivalsHouse_1F_Text_Good_Morning, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	setvar VAR_GOOD_MORNING_RIVAL, 1
	releaseall
	end

StarterTown_MaleRivalsHouse_1F_EventScript_GoodMorning::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	showobjectat 3, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox StarterTown_MaleRivalsHouse_1F_Text_Good_Morning, MSGBOX_DEFAULT
	callnative ClearMugshot
	waitmovement 0
	closemessage
	setvar VAR_GOOD_MORNING_RIVAL, 1
	releaseall
	end
	
StarterTown_RivalsHouse_1F_EventScript_DDFlag::
	goto_if_set FLAG_DOWNSTAIRS_DANGER, StarterTown_RivalsHouse_1F_EventScript_Downstairs_Danger
	end

StarterTown_RivalsHouse_1F_EventScript_Downstairs_Danger::
	playbgm MUS_ENCOUNTER_INTERVIEWER, 1
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq StarterTown_MaleRivalsHouse_1F_EventScript_Downstairs_Danger
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox StarterTown_RivalsHouse_1F_Text_What_Happened, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement 2, Rival_Mom_Step_Back
	applymovement 4, Rival_Move_To_TV
	applymovement OBJ_EVENT_ID_PLAYER, Player_Move_To_TV
	msgbox StarterTown_RivalsHouse_1F_Text_Todays_News, MSGBOX_DEFAULT
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER,Look_At_Both_Rival_And_Rival_Mom
	msgbox StarterTown_RivalsHouse_1F_Text_Outside_Now, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox StarterTown_RivalsHouse_1F_Text_Check_It_Out, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, Player_Move_To_Door
	applymovement 4, Rival_Move_To_Door
	waitmovement 0
	setflag FLAG_OBSIDIAN_INTRO
	goto_if_set FLAG_OBSIDIAN_INTRO, Rival_EventScript_Hide_Rival
	releaseall
	end

Rival_EventScript_Hide_Rival::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Rival_EventScript_Hide_MayRival
	removeobject 4
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	warp MAP_LITTLEROOT_TOWN, 255, 5, 9
	end

StarterTown_MaleRivalsHouse_1F_EventScript_Downstairs_Danger::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox StarterTown_RivalsHouse_1F_Text_What_Happened_Male, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement 2, Rival_Mom_Step_Back
	applymovement 5, Rival_Move_To_TV
	applymovement OBJ_EVENT_ID_PLAYER, Player_Move_To_TV
	msgbox StarterTown_RivalsHouse_1F_Text_Todays_News, MSGBOX_DEFAULT
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER,Look_At_Both_Rival_And_Rival_Mom
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox StarterTown_MaleRivalsHouse_1F_Text_Outside_Now, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	waitmovement 0
	msgbox StarterTown_MaleRivalsHouse_1F_Text_Check_It_Out, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Player_Move_To_Door
	applymovement 5, Rival_Move_To_Door
	waitmovement 0
	setflag FLAG_OBSIDIAN_INTRO
	goto_if_set FLAG_OBSIDIAN_INTRO, Rival_EventScript_Hide_Rival
	releaseall
	end

Rival_EventScript_Hide_MayRival::
	removeobject 5
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	warp MAP_LITTLEROOT_TOWN, 255, 5, 9
	end

FaceLeft:
	face_left
	step_end

Rival_Mom_Step_Back:
	walk_left
	face_up
	step_end

Rival_Move_To_TV:
	delay_16
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end
	
Player_Move_To_TV:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end
	
Look_At_Both_Rival_And_Rival_Mom:
	face_right
	delay_16
	face_left
	delay_16
	face_up
	step_end

Player_Move_To_Door:
	delay_16
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Rival_Move_To_Door:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

StarterTown_RivalsHouse_1F_Text_Good_Morning:
	.string "{RIVAL}'s Mom:Good Morning Sweetie.\p"
	.string "{RIVAL} is upstairs if you are looking\n"
	.string "for them.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GRAY}Thank you ma'am.$"

StarterTown_MaleRivalsHouse_1F_Text_Good_Morning:
	.string "{RIVAL}'s Mom:Good Morning Sweetie.\p"
	.string "{RIVAL} is upstairs if you are looking\n"
	.string "for them.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY}Thanks ma'am.$"

StarterTown_RivalsHouse_1F_Text_What_Happened:
	.string "{COLOR BLUE}{RIVAL}:{COLOR DARK_GRAY}What happened Mom!?\n"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GRAY}Are you okay!?\p"
	.string "{RIVAL}'s Mom: I'm okay just come look\n"
	.string "at this.$"

StarterTown_RivalsHouse_1F_Text_What_Happened_Male:
	.string "{COLOR RED}{RIVAL}:{COLOR DARK_GRAY}What happened Mom!?\n"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY}Are you okay!?\p"
	.string "{RIVAL}'s Mom: I'm okay just come look\n"
	.string "at this.$"

StarterTown_RivalsHouse_1F_Text_Todays_News:
	.string "In Today's News, a government funded\n"
	.string "organization, by the name of\l"
	.string "Obsidian, has made their way to\p"
	.string "Littleroot Town.\p"
	.string "It seems that they are there to state\n"
	.string "their goals for the world.$"

StarterTown_RivalsHouse_1F_Text_Outside_Now:
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GRAY}Is this literally happening\n"
	.string "outside right now!?$"

StarterTown_RivalsHouse_1F_Text_Check_It_Out:
	.string "{COLOR BLUE}{RIVAL}:{COLOR DARK_GRAY}Seems so.\n"
	.string "Let's go check it out.$"

StarterTown_MaleRivalsHouse_1F_Text_Outside_Now:
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY}No way this is happening\n"
	.string "outside right now!?$"

StarterTown_MaleRivalsHouse_1F_Text_Check_It_Out:
	.string "{COLOR RED}{RIVAL}:{COLOR DARK_GRAY}One way to find out.\n"
	.string "We got to go check it out.$"



