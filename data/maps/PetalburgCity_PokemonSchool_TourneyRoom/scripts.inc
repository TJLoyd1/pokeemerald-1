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
	step_end

PetalburgCity_PokemonSchool_TourneyRoom_Text_HurryUp:
	.string "Ignes: Hurry up slow ass!\p"
	.string "Unless you're scared then you might as\n"
	.string "well turn back now.$"

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_Tournament::
	lockall
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setvar VAR_PETALBURG_GYM_STATE, 3
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_CriticalHit, MSGBOX_DEFAULT
	closemessage
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
	setobjectxy 6, 18, 5
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
	setobjectxyperm 1, 13, 8
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
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, TourneyIgnes_Text_Defeat
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
	giveitem ITEM_LUCKY_EGG, 1
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_MakeGoodUse, MSGBOX_DEFAULT
	closemessage
	applymovement 2, CommentatorHeadsOffStage
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	removeobject 2
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setvar VAR_PETALBURG_GYM_STATE, 8
	releaseall
	end

PetalburgCity_PokemonSchool_TourneyRoom_EventScript_Tournament::
	lockall
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setvar VAR_PETALBURG_GYM_STATE, 3
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_CriticalHit, MSGBOX_DEFAULT
	closemessage
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
	setobjectxy 6, 18, 5
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
	setobjectxyperm 1, 13, 8
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
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, TourneyIgnes_Text_Defeat
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
	giveitem ITEM_LUCKY_EGG, 1
	msgbox PetalburgCity_PokemonSchool_TourneyRoom_Text_MakeGoodUse, MSGBOX_DEFAULT
	closemessage
	applymovement 2, CommentatorHeadsOffStage
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	removeobject 2
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setvar VAR_PETALBURG_GYM_STATE, 8
	releaseall
	end

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
	
TrainerHeadsTowardStage:
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_right
	step_end
	
MoveBackToCenterFieldFromLeft:
	walk_fast_right
	walk_fast_right
	step_end

WalkOffField:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
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

PetalburgCity_PokemonSchool_TourneyRoom_Text_CriticalHit:
	.string "Teddiursa with a Critical Hit Focus Punch\n"
	.string "finishes not only the Geodude, but also\l"
	.string "the battle!!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_NextTwoCompetitors:
	.string "It seems the next two competitors have\n"
	.string "made their way to the field!\p"
	.string "I wonder what excitement awaits us\n"
	.string "with this battle!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_BugPokemon:
	.string "My Bug Pokémon and I are gonna win\n"
	.string "this and no one will stop us!$"

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
	.string "however {PLAYER} looks like their ready\l"
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
	.string "I've been waiting to stomp you into\n"
	.string "the fucking ground.\p"
	.string "I'll show you how to be a REAL TRAINER!$"

PetalburgCity_PokemonSchool_TourneyRoom_Text_LetTheBattleCommence:
	.string "LET THE BATTLE COMMENCE!!!$"

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
