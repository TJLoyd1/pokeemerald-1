PetalburgCity_PokemonSchool_TourneyRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonSchool_TourneyRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_PokemonSchool_TourneyRoom_OnFrame
	.byte 0

PetalburgCity_PokemonSchool_TourneyRoom_OnTransition:
	compare VAR_PETALBURG_GYM_STATE, 1
	call_if_eq PetalburgCity_PokemonSchool_TourneyRoom_EventScript_ShowIgnes
	end

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_ShowIgnes::
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	addobject 1
	return

PetalburgCity_PokemonSchool_TourneyRoom_OnFrame:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_PokemonSchool_TourneyRoom_EventScript_ItsStarting
	.2byte 0

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_ItsStarting::
	lockall
	applymovement 1, HesAhead
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_HurryUp, MSGBOX_DEFAULT
	closemessage
	applymovement 1, HeadingTowardsField
	waitmovement 0
	setobjectxyperm 1, 23, 8
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

HesAhead:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

HeadingTowardsField:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgCity_PokemonSchool_TourneyRoom_Text_HurryUp:
	.string "Ignes: Hurry up slow ass!\p"
	.string "Unless you're scared then you might as\n"
	.string "well turn back now.$"

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_Tournament::
	lockall
	clearflag FLAG_HIDE_TOURNEY_ROOM_POKEMON
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
	setvar VAR_PETALBURG_GYM_STATE, 3
	waitmovement 0
	setobjectxy 5, 14, 8
	applymovement 5, Common_Movement_FaceLeft
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Camera_Moves_Center_Stage
	waitmovement 0
	playse SE_SUPER_EFFECTIVE
	applymovement 8, Geodude_Gets_Knocked_Back
	waitse
	playmoncry SPECIES_GEODUDE, 2
	waitmoncry
	waitmovement 0
	playse SE_APPLAUSE
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_CriticalHit, MSGBOX_DEFAULT
	closemessage
	waitse
	fadescreen 1
	playmoncry SPECIES_TEDDIURSA, 2
	waitmoncry
	removeobject 9
	removeobject 8
	removeobject 10
	applymovement 5, Common_Movement_FaceDown
	setobjectxy 5, 4, 6
	fadescreen 0
	applymovement OBJ_EVENT_ID_CAMERA, Camera_Moves_Back_To_Player
	waitmovement 0
	special RemoveCameraObject
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
	setobjectxyperm 10, 6, 6
	addobject 2
	addobject 3
	addobject 4
	addobject 5
	addobject 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setobjectxy 6, 18, 8
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHeadTowardsStage
	waitmovement 0
	applymovement 6, TrainerHeadsTowardStage
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_NextTwoCompetitors, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_BugPokemon, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_JAMES_2, Corinna_Text_Defeat
	special HealPlayerParty
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_GreatBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	setobjectxy 6, 21, 5
	applymovement 6, Common_Movement_FaceDown
	waitmovement 0
	setobjectxy 4, 18, 8
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesAchievement, MSGBOX_DEFAULT
	closemessage
	fadescreen 0
	applymovement 4, TrainerHeadsTowardStage
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_NoMercyPlayer, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Teddiursa, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_HALEY_2, Crystal_Text_Defeat
	special HealPlayerParty
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_OnceAgain, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	setobjectxy 4, 19, 6
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setobjectxy 1, 23, 8
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	setobjectxy OBJ_EVENT_ID_PLAYER, 1, 8
	special SpawnCameraObject
	setobjectxy OBJ_EVENT_ID_CAMERA, 11, 8
	fadescreen 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Finale, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, MoveRightTowardsIgnes
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesBattleIntro, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	playse SE_APPLAUSE
	applymovement OBJ_EVENT_ID_CAMERA, IgnesHeadsToField
	applymovement 1, IgnesHeadsToField
	waitmovement 0
	waitse
	setobjectxyperm 1, 14, 8
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToCenterFieldFromRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveLeftTowardsPlayer
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_PlayerBattleIntro, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	playse SE_APPLAUSE
	applymovement OBJ_EVENT_ID_CAMERA, PlayerHeadsToField
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHeadsToField
	waitmovement 0
	waitse
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToCenterFieldFromLeft
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesShitTalking, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_LetTheBattleCommence, MSGBOX_DEFAULT
	closemessage
	special RemoveCameraObject
	setvar VAR_MUGSHOT_ID, MUGSHOT_IGNES
	trainerbattle_continue_after_lose TRAINER_WALLY_MAUVILLE, TourneyIgnes_Text_Defeat, TourneyIgnes_Text_Defeat,PetalburgCity_PokemonSchool_TourneyRoom_EventScript_EndOfIgnesBattle
	end


PetalburgCity_PokemonSchool_TourneyRoom_EventScript_Tournament2::
	lockall
	clearflag FLAG_HIDE_TOURNEY_ROOM_POKEMON
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
	setvar VAR_PETALBURG_GYM_STATE, 3
	waitmovement 0
	setobjectxy 5, 14, 8
	applymovement 5, Common_Movement_FaceLeft
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Camera_Moves_Center_Stage
	waitmovement 0
	playse SE_SUPER_EFFECTIVE
	applymovement 8, Geodude_Gets_Knocked_Back
	waitse
	playmoncry SPECIES_GEODUDE, 2
	waitmoncry
	waitmovement 0
	playse SE_APPLAUSE
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_CriticalHit, MSGBOX_DEFAULT
	closemessage
	waitse
	fadescreen 1
	playmoncry SPECIES_TEDDIURSA, 2
	waitmoncry
	removeobject 9
	removeobject 8
	removeobject 10
	applymovement 5, Common_Movement_FaceDown
	setobjectxy 5, 4, 6
	fadescreen 0
	applymovement OBJ_EVENT_ID_CAMERA, Camera_Moves_Back_To_Player
	waitmovement 0
	special RemoveCameraObject
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
	setobjectxyperm 10, 6, 6
	addobject 2
	addobject 3
	addobject 4
	addobject 5
	addobject 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setobjectxy 6, 18, 8
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHeadTowardsStage2
	waitmovement 0
	applymovement 6, TrainerHeadsTowardStage
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_NextTwoCompetitors, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_BugPokemon, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_JAMES_2, Corinna_Text_Defeat
	special HealPlayerParty
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_GreatBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	setobjectxy 6, 21, 5
	applymovement 6, Common_Movement_FaceDown
	waitmovement 0
	setobjectxy 4, 18, 8
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesAchievement, MSGBOX_DEFAULT
	closemessage
	fadescreen 0
	applymovement 4, TrainerHeadsTowardStage
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_NoMercyPlayer, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Teddiursa, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_HALEY_2, Crystal_Text_Defeat
	special HealPlayerParty
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_OnceAgain, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	setobjectxy 4, 19, 6
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setobjectxy 1, 23, 8
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	setobjectxy OBJ_EVENT_ID_PLAYER, 1, 8
	special SpawnCameraObject
	setobjectxy OBJ_EVENT_ID_CAMERA, 11, 8
	fadescreen 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Finale, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, MoveRightTowardsIgnes
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesBattleIntro, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, IgnesHeadsToField
	applymovement 1, IgnesHeadsToField
	waitmovement 0
	setobjectxyperm 1, 14, 8
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToCenterFieldFromRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveLeftTowardsPlayer
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_PlayerBattleIntro, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, PlayerHeadsToField
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHeadsToField
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToCenterFieldFromLeft
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesShitTalking, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_LetTheBattleCommence, MSGBOX_DEFAULT
	closemessage
	special RemoveCameraObject
	setvar VAR_MUGSHOT_ID, MUGSHOT_IGNES
	trainerbattle_continue_after_lose TRAINER_WALLY_MAUVILLE, TourneyIgnes_Text_Defeat, TourneyIgnes_Text_Defeat,PetalburgCity_PokemonSchool_TourneyRoom_EventScript_EndOfIgnesBattle
	end

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_EndOfIgnesBattle::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq PetalburgCity_PokemonSchool_TourneyRoom_EventScript_TournamentContinuationLost
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PetalburgCity_PokemonSchool_TourneyRoom_EventScript_TournamentContinuation
	end
	
PetalburgCity_PokemonSchool_TourneyRoom_EventScript_TournamentContinuation::
	special HealPlayerParty
	playbgm DP_SEQ_WINGINGA, 1
	fadedefaultbgm 
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_WithTheIncredible, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesSoreLoser, MSGBOX_DEFAULT
	closemessage
	applymovement 1, WalkOffField
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_StayForPrize, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, BackToPlayer
	waitmovement 0
	fadescreen 1
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	fadescreen 0
	applymovement 2, CommentatorHeadsTowardsPlayer
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Prize, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM27, 1
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_MakeGoodUse, MSGBOX_DEFAULT
	closemessage
	applymovement 2, CommentatorHeadsOffStage
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	removeobject 2
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_TRAINER_SCHOOL_COMPLETED
	setvar VAR_PETALBURG_GYM_STATE, 8
	releaseall
	end

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_TournamentContinuationLost::
	special HealPlayerParty
	playbgm DP_SEQ_WINGINGA, 1
	fadedefaultbgm 
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_WithTheIncredibleIgnesWon, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_StayForPrizeIgnes, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_PlayerAcceptsDefeat, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkOffField
	waitmovement 0
	fadescreen 1
	setflag FLAG_REMOVE_WARP_FADE
	setflag FLAG_TRAINER_SCHOOL_COMPLETED
	setvar VAR_PETALBURG_GYM_STATE, 8
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_GottaTrainHarder, MSGBOX_AUTOCLOSE
	warp MAP_PETALBURG_CITY_POKEMON_CENTER_1F, 255, 7, 13
	releaseall
	end

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_RightSideTournament::
	lockall
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setvar VAR_PETALBURG_GYM_STATE, 3
	removeobject 6
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_CriticalHit, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setobjectxy 8, 5, 8
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHeadTowardsStageRightSide
	waitmovement 0
	applymovement 8, TrainerHeadsTowardStageRightSide
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_NextTwoCompetitors, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_BugPokemon, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_JAMES_2, Corinna_Text_Defeat
	special HealPlayerParty
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_GreatBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	setobjectxy 8, 6, 5
	applymovement 6, Common_Movement_FaceDown
	waitmovement 0
	setobjectxy 4, 5, 8
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesAchievement, MSGBOX_DEFAULT
	closemessage
	fadescreen 0
	applymovement 4, TrainerHeadsTowardStageRightSide
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_NoMercyPlayer, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Teddiursa, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_HALEY_2, Crystal_Text_Defeat
	special HealPlayerParty
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_OnceAgain, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	setobjectxy 4, 19, 6
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setobjectxy 1, 1, 8
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	setobjectxy OBJ_EVENT_ID_PLAYER, 23, 8
	special SpawnCameraObject
	setobjectxy OBJ_EVENT_ID_CAMERA, 11, 8
	fadescreen 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Finale, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, MoveLeftTowardsPlayer
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesBattleIntro, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, PlayerHeadsToField
	applymovement 1, PlayerHeadsToField
	waitmovement 0
	setobjectxyperm 1, 9, 8
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToCenterFieldFromLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveRightTowardsIgnes
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_PlayerBattleIntro, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, IgnesHeadsToField
	applymovement OBJ_EVENT_ID_PLAYER, IgnesHeadsToField
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToCenterFieldFromRight
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesShitTalking, MSGBOX_DEFAULT
	closemessage
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_LetTheBattleCommence, MSGBOX_DEFAULT
	closemessage
	special RemoveCameraObject
	setvar VAR_MUGSHOT_ID, MUGSHOT_IGNES
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, TourneyIgnes_Text_Defeat
	special HealPlayerParty
	playbgm DP_SEQ_WINGINGA, 1
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_WithTheIncredible, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm 
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesSoreLoser, MSGBOX_DEFAULT
	closemessage
	applymovement 1, WalkOffFieldRightSide
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_StayForPrize, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, BackToPlayer
	waitmovement 0
	fadescreen 1
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	fadescreen 0
	applymovement 2, CommentatorHeadsTowardsPlayerRightSide
	waitmovement 0
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_Prize, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM27, 1
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_MakeGoodUse, MSGBOX_DEFAULT
	closemessage
	applymovement 2, CommentatorHeadsOffStageRightSide
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	removeobject 2
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_TRAINER_SCHOOL_COMPLETED
	setvar VAR_PETALBURG_GYM_STATE, 8
	releaseall
	end

Camera_Moves_Center_Stage:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
	
Geodude_Gets_Knocked_Back:
	walk_fast_right
	walk_in_place_fastest_down
	delay_16
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_right
	step_end

Camera_Moves_Back_To_Player:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PlayerHeadTowardsStage:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PlayerHeadTowardsStage2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PlayerHeadTowardsStageRightSide:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TrainerHeadsTowardStage:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TrainerHeadsTowardStageRightSide:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MoveRightTowardsIgnes:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end

IgnesHeadsToField:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MoveBackToCenterFieldFromRight:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MoveLeftTowardsPlayer:
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	step_end

PlayerHeadsToField:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
MoveBackToCenterFieldFromLeft:
	walk_fast_right
	walk_fast_right
	step_end

PlayerWalkOffField:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WalkOffField:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WalkOffFieldRightSide:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BackToPlayer:
	walk_fastest_left
	walk_fastest_left
	step_end

CommentatorHeadsTowardsPlayer:
	walk_down
	walk_down
	walk_left
	step_end

CommentatorHeadsTowardsPlayerRightSide:
	walk_down
	walk_down
	walk_right
	step_end

CommentatorHeadsOffStage:
	walk_down
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CommentatorHeadsOffStageRightSide:
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
PetalburgCity_PokemonSchool_TourneyRoom_Text_CriticalHit:
	.string "Teddiursa with a Super Effective\n"
	.string "Focus Punch finishes off both the\l"
	.string "Geodude and also the battle!!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_NextTwoCompetitors:
	.string "It seems the next two competitors have\n"
	.string "made their way to the field!\p"
	.string "I wonder what excitement awaits us\n"
	.string "with this battle!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_BugPokemon:
	.string "Corinna: My Bug Pokémon and I are gonna\n"
	.string "win this and no one will stop us!$"

Corinna_Text_Defeat:
	.string "I can't believe I lost...$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_GreatBattle:
	.string "And That concludes the battle folks!\p"
	.string "The Silent-But-Deadly Trainer takes the\n"
	.string "win to this great battle!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesAchievement:
	.string "The Completely Determined Ignes has\n"
	.string "taken an easy victory in his battle!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_NoMercyPlayer:
	.string "It seems the next competitor is ready,\n"
	.string "however {PLAYER} looks like they're ready\l"
	.string "to take her out with no mercy!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_Teddiursa:
	.string "My Teddiursa is not only cute, but\n"
	.string "very strong too!$"

Crystal_Text_Defeat:
	.string "Noooo I Lost...$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_OnceAgain:
	.string "Once again {PLAYER} take an easy\n"
	.string "victory over their opponent!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_Finale:
	.string "Here we are Folks!\p"
	.string "After such exciting battles, we have\n"
	.string "finally reached our climax!\p"
	.string "This is the final battle of this\n"
	.string "tournament between two trainers that\l"
	.string "didn't back down to the challenge ahead\p"
	.string "of them!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesBattleIntro:
	.string "On this side, we have someone who seems\n"
	.string "to think of himself as better than\l"
	.string "everyone else.\p"
	.string "He aggressively pushes ahead in both\n"
	.string "battles and unexpected situations.\p"
	.string "He claims after leaving here, he's going\n"
	.string "to explore the region and become\l"
	.string "the next champion!\p"
	.string "HERE IS IGNES!!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_PlayerBattleIntro:
	.string "And standing opposite of him, we have\n"
	.string "someone with a sense of determination to\l"
	.string "stop those who plans to hurt this\p"
	.string "region and have fun while doing so.\p"
	.string "They only ever talk when need be and\n"
	.string "likes to be called Silent-But-Deadly.\p"
	.string "They also are trying to become the next\n"
	.string "champion even if that means crushing\l"
	.string "Ignes's dreams.\p"
	.string "HERE IS {PLAYER}!!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesShitTalking:
	.string "Ignes: I've been waiting to stomp you\n"
	.string "into the fucking ground.\p"
	.string "I'll show you how to be a REAL TRAINER!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_LetTheBattleCommence:
	.string "Announcer: LET THE BATTLE COMMENCE!!!$"

TourneyIgnes_Text_Defeat:
	.string"No-No damn way I actually lost!!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_WithTheIncredible:
	.string "With that, This INCREDIBLE BATTLE comes\n"
	.string "to an exciting end!\p"
	.string "And the Winner is...\p"
	.string "{PLAYER}!!!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesSoreLoser:
	.string "I won't accept defeat so easily.\p"
	.string "Next time I see you, I'll be stronger\n"
	.string "than you'll ever be.$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_StayForPrize:
	.string "{PLAYER}, I need you to stay for\n"
	.string "the reward for winning the tournament.$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_Prize:
	.string "Those battles were full of excitement\n"
	.string "and I'm sure we were all at the edge of\l"
	.string "seats watching your and Ignes's battles.\p"
	.string "Anyway, For Winning, I'm giving you this.$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_MakeGoodUse:
	.string "I hope you can make good use of that\n"
	.string "during your journey.$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_WithTheIncredibleIgnesWon:
	.string "With that, This INCREDIBLE BATTLE comes\n"
	.string "to an exciting end!\p"
	.string "And the Winner is...\p"
	.string "IGNES!!!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_StayForPrizeIgnes:
	.string "Ignes, I need you to stay for\n"
	.string "the reward for winning the tournament.$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_PlayerAcceptsDefeat:
	.string "{PLAYER}: I'll let you have this one but,\n"
	.string "next time I see you, I'll be stronger\l"
	.string "than you'll ever be.\p"
	.string "Ignes: Whatever you fucking loser.\p"
	.string "Go back home and cry about it to\n"
	.string "mommy.\p"
	.string "HAHAHAHAHA...$"
	
PetalburgCity_PokemonSchool_TourneyRoom_Text_GottaTrainHarder:
	.string "If I can't beat a simple trainer like\n"
	.string "Ignes, there's no way I'm beating\l"
	.string "the 1st Gym.\p"
	.string "I don't have an option anymore.\p"
	.string "I NEED to train harder than before...$"

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_RightSideNotAvailable::
	lockall
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesIsHere, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TurnAroundToHeadToLeftSide
	waitmovement 0
	releaseall
	end

TurnAroundToHeadToLeftSide:
	walk_in_place_fastest_left
	walk_left
	step_end

PetalburgCity_PokemonSchool_TourneyRoom_Text_IgnesIsHere:
	.string "{PLAYER}: I should go to the other side\n"
	.string "since Ignes is this way.$"
