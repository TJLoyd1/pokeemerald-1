Route106_MapScripts:: @ 81EE489
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route106_OnFrame
	.byte 0

Route106_OnFrame:
	map_script_2 VAR_ROUTE606_ADMINS, 0, Route606_EventScript_AdminEncounter
	.2byte 0

Route106_EventScript_TrainerTipsSign:: @ 81EE48A
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas:: @ 81EE493
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla:: @ 81EE4AA
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot:: @ 81EE4C1
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle:: @ 81EE4ED
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_Ned:: @ 81EE523
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Andre:: @ 81EE493
	trainerbattle_single TRAINER_ANDRE, Route106_Text_AndreIntro, Route106_Text_AndreDefeat
	msgbox Route106_Text_AndrePostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Angus:: @ 81EE493
	trainerbattle_single TRAINER_ANGUS, Route106_Text_AngusIntro, Route106_Text_AngusDefeat
	msgbox Route106_Text_AngusPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Alysia:: @ 81EE493
	trainerbattle_single TRAINER_ALYSIA, Route106_Text_AlysiaIntro, Route106_Text_AlysiaDefeat
	msgbox Route106_Text_AlysiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_Text_TrainerTips: @ 81EE53A
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

Route606_EventScript_AdminEncounter::
	lockall
	msgbox Route606_Text_RhyosCantSee, MSGBOX_DEFAULT
	closemessage
	applymovement 9, RhyosLookingAround
	waitmovement 0
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route606_Text_RhyosDamnIt, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route606_Text_RhyosGetsMettaosAttention, MSGBOX_DEFAULT
	closemessage
	applymovement 10, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 9, Common_Movement_FaceUp
	applymovement 10, Common_Movement_FaceUp
	waitmovement 0
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route606_Text_MatteoGruntsCantWork, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_WalkUp
	applymovement 10, Common_Movement_WalkUp
	waitmovement 0
	msgbox Route606_Text_MadeItThisFar, MSGBOX_AUTOCLOSE
	msgbox Route606_Text_IgnesInterruptsLikeUsual, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_QuestionMark
	applymovement 10, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 11, IgnesAppears
	waitmovement 0
	msgbox Route606_Text_OnlyOnePersonCanStomp, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route606_Text_IllHelpThisTime, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	multi_fixed_2_vs_2 TRAINER_ROUTE_606_RHYOS, Route606_Text_RhyosDefeat, TRAINER_ROUTE_606_METTAO, Route606_Mettao_Text_Defeat, TRAINER_ROUTE_606_IGNES, TRAINER_BACK_PIC_IGNES
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq Route610_EventScript_PlayerLost
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route606_EventScript_AdminsLost
    end

Route606_EventScript_AdminsLost::
	applymovement 9, AdminsStepBack
	applymovement 10, AdminsStepBack
	waitmovement 0
	msgbox Route606_Text_DamnBrats, MSGBOX_DEFAULT
	closemessage
	applymovement 9, RhyosWalksAway
	applymovement 10, MatteoWalksAway
	waitmovement 0
	setflag FLAG_HIDE_GRANITE_CAVE_GRUNTS
	removeobject 9
	removeobject 10
	applymovement 11, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route606_Text_IgnesCallsThemWeak, MSGBOX_DEFAULT
	closemessage
	applymovement 11, IgnesPushesPlayer
	applymovement OBJ_EVENT_ID_PLAYER, PlayerGetsPushedBack
	waitmovement 0
	msgbox Route606_Text_ImOuttaHere, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_WalkUp
	waitmovement 0
	playse SE_EXIT
	fadescreen 1
	removeobject 11
	setvar VAR_ROUTE606_ADMINS, 1
	setflag FLAG_HIDE_ROUTE_606_IGNES
	fadescreen 0
	releaseall
	end

RhyosLookingAround:
	face_left
	delay_16
	delay_16
	walk_down
	delay_8
	face_right
	delay_16
	delay_8
	walk_up
	step_end

IgnesAppears:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

AdminsStepBack:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MatteoWalksAway:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RhyosWalksAway:
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IgnesPushesPlayer:
	walk_in_place_left
	delay_16
	walk_left
	step_end

PlayerGetsPushedBack:
	lock_facing_direction
	walk_fast_left
	walk_fast_left
	unlock_facing_direction
	step_end

Route606_Text_RhyosCantSee:
	.string "Rhyos: All this damn sand is all in\n"
	.string "my face.\l"
	.string "I can't see shit.\p"
	.string "Mettao: We're almost there so stop\n"
	.string "complaining Rhyos.$"

Route606_Text_RhyosDamnIt:
	.string "Goddamn it...\n"
	.string "Those useless ass grunts failed to\l"
	.string "do one simple task.$"

Route606_Text_RhyosGetsMettaosAttention:
	.string "Rhyos: Stop spacing out Mettao.\p"
	.string "We seem to have an uninvited visitor.$"

Route606_Text_MatteoGruntsCantWork:
	.string "Mettao: GAHHHH!\p"
	.string "Those fucking grunts can't ever do\n"
	.string "their damn job.$"

Route606_Text_MadeItThisFar:
	.string "Rhyos: You thought I'd forgotten your\n"
	.string "face kid?\p"
	.string "Even after what I did to you in\n"
	.string "Claywood, you still decided to interfer\l"
	.string "with our plans.\p"
	.string "Mettao: So you're one of the brats Rhyos\n"
	.string "mentioned about helping our old pal, May.\p"
	.string "Since you made it this far how\n"
	.string "about I give you a gift with a side\l"
	.string "of as-$"

Route606_Text_IgnesInterruptsLikeUsual:
	.string "Ignes: What the hell is going on here!?$"

Route606_Text_OnlyOnePersonCanStomp:
	.string "Rhyos: Who are you!?\n"
	.string "Mettao: Who the hell are you!?\p"
	.string "Ignes: Don't worry about who I fucking\n"
	.string "am you damn punks.\p"
	.string "Just know If anyone is gonna stop you\n"
	.string "and stomp this guy into the ground,\l"
	.string "it's gonna be me, motherfucking Ignes!$"

Route606_Text_IllHelpThisTime:
	.string "Ignes: I'll help you this time but,\n"
	.string "never expect this to happen ever again.\p"
	.string "Mettao: Even if there's two of you\n"
	.string "still gonna get wiped!$"

Route606_Text_RhyosDefeat:
	.string "...$"

Route606_Mettao_Text_Defeat:
	.string "GAAAAHHH!!!$"

Route606_Text_DamnBrats:
	.string "Rhyos: N-No...\n"
	.string "Mettao: Tch... Damn Brats\p"
	.string "Fine, you win this time but next\n"
	.string "time you won't be so lucky.\p"
	.string "Rhyos: You, your little buddies, and\n"
	.string "May will never be safe as long as\l"
	.string "Team Obsidian is around.$"

Route606_Text_IgnesCallsThemWeak:
	.string "Ignes: They weren't even competition.\p"
	.string "They were weak as hell, maybe even weaker\n"
	.string "then you.\p"
	.string "I guess trash will always be trash.\p"
	.string "Anyway...\p"
	.string "Get out of my way so I can go battle\n"
	.string "some actual strong trainers I spotted\l"
	.string "in this cave.$"

Route606_Text_ImOuttaHere:
	.string "Ignes: I'm outta here you damn nerd.$"
