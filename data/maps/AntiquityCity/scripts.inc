AntiquityCity_MapScripts::
	.byte 0

AntiquityCity_EventScript_NoGood_Flagset::
	goto_if_set FLAG_BADGE01_GET, AntiquityCity_EventScript_UptoNoGood
	release
	end
	
AntiquityCity_EventScript_UptoNoGood::
	lockall
	setvar VAR_CAMERA_MOVEMENT_TEST, 1
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA
	setflag FLAG_HIDE_GRANITE_CAVE_GRUNTS
	clearflag FLAG_HIDE_ANTIQUITY_CITY_GRUNT
	addobject 4
	addobject 5
	setobjectxyperm 6, 27, 15
	setobjectxyperm 7, 30, 15
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MovetoObsidianAdminsTalking
	waitmovement 0
	playbgm BW_SEQ_BGM_E_SAGE, 1
	applymovement 6, Common_Movement_FaceUp
	applymovement 7, Common_Movement_FaceUp
	waitmovement 0
	applymovement 4, RhyosLooksatMettao
	waitmovement 0
	msgbox AntiquityCity_Text_Rhyos_Speaking, MSGBOX_DEFAULT
	closemessage
	msgbox AntiquityCity_Text_Mettao_Speaking, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	msgbox AntiquityCity_Text_RhyosCommandsGrunts, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceRight
	waitmovement 0
	msgbox AntiquityCity_Text_LetsGetThisOverWith, MSGBOX_DEFAULT
	closemessage
	applymovement 4, EntersCave
	applymovement 5, EntersCave
	waitmovement 0
	playse SE_EXIT
	fadescreen 1
	removeobject 4
	removeobject 5
	fadescreen 0
	applymovement 6, BlocksCaveEntranceLeft
	applymovement 7, BlocksCaveEntranceRight
	waitmovement 0
	setobjectxyperm 6, 28, 10
	setobjectxyperm 7, 29, 10
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	msgbox AntiquityCity_Text_FeelLikeSomeone, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

AntiquityCity_EventScript_NoGood_Flagset2::
	goto_if_set FLAG_BADGE01_GET, AntiquityCity_EventScript_UptoNoGood2
	release
	end

AntiquityCity_EventScript_UptoNoGood2::
	lockall
	setvar VAR_CAMERA_MOVEMENT_TEST, 1
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA
	setflag FLAG_HIDE_GRANITE_CAVE_GRUNTS
	clearflag FLAG_HIDE_ANTIQUITY_CITY_GRUNT
	addobject 4
	addobject 5
	setobjectxyperm 6, 27, 15
	setobjectxyperm 7, 30, 15
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MovetoObsidianAdminsTalking2
	waitmovement 0
	playbgm BW_SEQ_BGM_E_SAGE, 1
	applymovement 6, Common_Movement_FaceUp
	applymovement 7, Common_Movement_FaceUp
	waitmovement 0
	applymovement 4, RhyosLooksatMettao
	waitmovement 0
	msgbox AntiquityCity_Text_Rhyos_Speaking, MSGBOX_DEFAULT
	closemessage
	msgbox AntiquityCity_Text_Mettao_Speaking, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	msgbox AntiquityCity_Text_RhyosCommandsGrunts, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceRight
	waitmovement 0
	msgbox AntiquityCity_Text_LetsGetThisOverWith, MSGBOX_DEFAULT
	closemessage
	applymovement 4, EntersCave
	applymovement 5, EntersCave
	waitmovement 0
	playse SE_EXIT
	fadescreen 1
	removeobject 4
	removeobject 5
	fadescreen 0
	applymovement 6, BlocksCaveEntranceLeft
	applymovement 7, BlocksCaveEntranceRight
	waitmovement 0
	setobjectxyperm 6, 28, 10
	setobjectxyperm 7, 29, 10
	applymovement 6, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToPlayer2
	waitmovement 0
	special RemoveCameraObject
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	msgbox AntiquityCity_Text_FeelLikeSomeone, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

 
AntiquityCity_EventScript_GruntGuardsFemale::
	lockall
	playbgm BW_SEQ_BGM_E_PLASMA, 1
	applymovement 6, Common_Movement_QuestionMark
	applymovement 7, Common_Movement_QuestionMark
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq AntiquityCity_EventScript_GruntGuardsMale
	msgbox AntiquityCity_Text_GruntGuardsPrepareToBattleFemale, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ANTIQUITY_CITY_GRUNT_1, AntiquityCity_Text_Grunt1_Defeated
	applymovement 6, Common_Movement_ExclamationMark
	msgbox AntiquityCity_Text_Grunt1_Lost, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ANTIQUITY_CITY_GRUNT_2, AntiquityCity_Text_Grunt2_Defeated
	msgbox AntiquityCity_Text_Grunt2_Lost, MSGBOX_DEFAULT
	closemessage
	applymovement 6, Grunt1Moves
	applymovement 7, Grunt2Moves
	applymovement OBJ_EVENT_ID_PLAYER, PlayerBacksAwayFromGrunts
	waitmovement 0
	setobjectxyperm 6, 27, 12
	setobjectxyperm 7, 30, 12
	msgbox AntiquityCity_Text_PlayerTauntsGruntsFemale
	clearflag FLAG_HIDE_GRANITE_CAVE_GRUNTS
	setflag FLAG_HIDE_ANTIQUITY_CITY_GRUNT
	closemessage
	setvar VAR_ANTIQUITY_CITY_GRUNTS, 1
	setflag FLAG_ANTIQUITY_CITY_GRUNT_DEFEATED
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

AntiquityCity_EventScript_GruntGuardsMale::
	msgbox AntiquityCity_Text_GruntGuardsPrepareToBattleMale, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ANTIQUITY_CITY_GRUNT_1, AntiquityCity_Text_Grunt1_Defeated
	msgbox AntiquityCity_Text_Grunt1_Lost, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ANTIQUITY_CITY_GRUNT_2, AntiquityCity_Text_Grunt2_Defeated
	msgbox AntiquityCity_Text_Grunt2_Lost, MSGBOX_DEFAULT
	closemessage
	applymovement 6, Grunt1Moves
	applymovement 7, Grunt2Moves
	applymovement OBJ_EVENT_ID_PLAYER, PlayerBacksAwayFromGrunts
	waitmovement 0
	setobjectxyperm 6, 27, 12
	setobjectxyperm 7, 30, 12
	msgbox AntiquityCity_Text_PlayerTauntsGruntsMale
	clearflag FLAG_HIDE_GRANITE_CAVE_GRUNTS
	setflag FLAG_HIDE_ANTIQUITY_CITY_GRUNT
	closemessage
	setvar VAR_ANTIQUITY_CITY_GRUNTS, 1
	setflag FLAG_ANTIQUITY_CITY_GRUNT_DEFEATED
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

AntiquityCity_EventScript_GruntGuard1::
	lockall
	setobjectxyperm 6, 27, 12
	goto_if_set FLAG_ANTIQUITY_CITY_GRUNT_DEFEATED, AntiquityCity_EventScript_GruntGuardsScaredOfJobLoss1
	releaseall
	end

AntiquityCity_EventScript_GruntGuardsScaredOfJobLoss1::
	faceplayer
	msgbox AntiquityCity_Text_OldPlasmaMember, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

AntiquityCity_EventScript_GruntGuard2::
	lockall
	setobjectxyperm 7, 30, 12
	goto_if_set FLAG_ANTIQUITY_CITY_GRUNT_DEFEATED, AntiquityCity_EventScript_GruntGuardsScaredOfJobLoss2
	releaseall
	end

AntiquityCity_EventScript_GruntGuardsScaredOfJobLoss2::
	faceplayer
	msgbox AntiquityCity_Text_OldGalacticMember, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

AntiquityCity_EventScript_Sign1::
	msgbox AntiquityCity_Text_Sure, MSGBOX_SIGN
	release
	end

AntiquityCity_EventScript_Camper::
	msgbox AntiquityCity_Text_FromTheWoods, MSGBOX_NPC
	release
	end

AntiquityCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_ge AntiquityCity_EventScript_BadMemory
	msgbox AntiquityCity_Text_Brittlebones, MSGBOX_DEFAULT
	checkitem ITEM_TM62, 1
	compare VAR_RESULT, 1
	msgbox AntiquityCity_Text_Acrobatics, MSGBOX_DEFAULT
	giveitem ITEM_TM62, 1
	compare VAR_RESULT, 0
	goto_if_eq AntiquityCity_EventScript_BagisFull
	release
	end

AntiquityCity_EventScript_OldWoman::
	lock
	msgbox AntiquityCity_Text_UsedtoBe, MSGBOX_NPC
	closemessage
	release
	end

MovetoObsidianAdminsTalking:
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_right
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

MovetoObsidianAdminsTalking2:
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_right
	walk_right
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
	
RhyosLooksatMettao:
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
	
MoveBackToPlayer:
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
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
	walk_left
	walk_left
	walk_up
	walk_up
	step_end
	
MoveBackToPlayer2:
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
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
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

EntersCave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
AntiquityCity_Text_UsedtoBe:
	.string "Antiquity City used to be so pretty and\n"
	.string "beautiful back in the day.$"

AntiquityCity_EventScript_BadMemory::
	msgbox AntiquityCity_Text_BadMemory, MSGBOX_DEFAULT
	release
	end

AntiquityCity_EventScript_BagisFull::
	msgbox AntiquityCity_Text_BagisFull, MSGBOX_DEFAULT
	release
	end

AntiquityCity_Text_Brittlebones:
	.string "These old brittle bones can't handle the\n"
	.string "acrobatics I used to do back in the day.\p"
	.string "Maybe you as a youngin can handle it.$"

AntiquityCity_Text_Acrobatics:
	.string "With this move, the user nimbly strikes the target.\n"
	.string "If the user is not holding an item, this\l"  
	.string "attack inflicts massive damage.$"

AntiquityCity_Text_BadMemory:
	.string "Hmm...\n"
	.string "I can't seem to remember if I gave you\l"
	.string "my gift already.$"

AntiquityCity_Text_BagisFull:
	.string "Your BAG is full.$"

AntiquityCity_Text_Sure:
	.string "Enter at your own risk because\n"
	.string "you will get bombarded by the\l"
	.string "Devs of this game, so be CAREFUL.$"

AntiquityCity_Text_FromTheWoods:
	.string "I was just in Petalburg Woods looking\n"
	.string "for my girlfriend, but I couldn't\l"
	.string "find her.$"

AntiquityCity_Text_Rhyos_Speaking:
	.string "Rhyos: Are you sure this is the exact\n"
	.string "location to get to where the boss\l"
	.string "needs us to gather test subjects\p"
	.string	"Mettao?$"
	
AntiquityCity_Text_Mettao_Speaking:
	.string "Mettao: Of course I am...\n"
	.string "Boss said we gotta go through G-Cave\l"
	.string "to get there and this is how we do it.$"

AntiquityCity_Text_LetsGetThisOverWith:
	.string "Rhyos: Hmmm...\p"
	.string "Let's hurry up and get this job\n"
	.string "done so I can finally get my revenge\l"
	.string "on those two brats and Birch.$"

AntiquityCity_Text_FeelLikeSomeone:
	.string "{PLAYER}: Why do I feel like someone's\n"
	.string "talking about me??$"
  	
Script_ItemDemonstration::
	lock
	faceplayer
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	checkitem ITEM_POKE_BALL, 999
	compare VAR_RESULT, 1
	goto_if_ge Script_HasPotionsAlready
	msgbox Text_GivingPotion, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 999
	compare VAR_RESULT, 0
	goto_if_eq Script_BagIsFullDev
	release
	end

Script_HasPotionsAlready::
	msgbox Text_HasPotionsAlready, MSGBOX_DEFAULT
	release
	end

Script_BagIsFullDev::
	msgbox Text_BagIsFullDev, MSGBOX_DEFAULT
	release
	end

Script_ItemDemonstration5::
	lock
	faceplayer
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	checkitem ITEM_POTION, 999
	compare VAR_RESULT, 1
	goto_if_ge Script_HasPotionsAlready5
	msgbox Text_GivingPotion5, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 999
	compare VAR_RESULT, 0
	goto_if_eq Script_BagIsFullDev5
	release
	end

Script_HasPotionsAlready5::
	msgbox Text_HasPotionsAlready5, MSGBOX_DEFAULT
	release
	end

Script_BagIsFullDev5::
	msgbox Text_BagIsFullDev5, MSGBOX_DEFAULT
	release
	end

Script_ItemDemonstration6::
	lock
	faceplayer
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	checkitem ITEM_RARE_CANDY, 999
	compare VAR_RESULT, 1
	goto_if_ge Script_HasPotionsAlready6
	msgbox Text_GivingPotion6, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 999
	compare VAR_RESULT, 0
	goto_if_eq Script_BagIsFullDev6
	release
	end

Script_HasPotionsAlready6::
	msgbox Text_HasPotionsAlready5, MSGBOX_DEFAULT
	release
	end

Script_BagIsFullDev6::
	msgbox Text_BagIsFullDev6, MSGBOX_DEFAULT
	release
	end

Text_ItemGiveaway:
	.string "The Dev Team has a gift for you.\n"
	.string "Rare Candy giveaway today.$"

Text_GivingPotion:
	.string "Here you go!$"

Text_HasPotionsAlready:
	.string "You already have these candies.\n"
	.string "Don't be greedy!$"

Text_BagIsFullDev:
	.string "Your BAG is full.$"

Text_ItemGiveaway5:
	.string "The Dev Team has a gift for you.\n"
	.string "Rare Candy giveaway today.$"

Text_GivingPotion5:
	.string "Here you go!$"

Text_HasPotionsAlready5:
	.string "You already have these candies.\n"
	.string "Don't be greedy!$"

Text_BagIsFullDev5:
	.string "Your BAG is full.$"

Text_ItemGiveaway6:
	.string "The Dev Team has a gift for you.\n"
	.string "Rare Candy giveaway today.$"

Text_GivingPotion6:
	.string "Here you go!$"

Text_HasPotionsAlready6:
	.string "You already have these candies.\n"
	.string "Don't be greedy!$"

Text_BagIsFullDev6:
	.string "Your BAG is full.$"

AntiquityCity_Text_RhyosCommandsGrunts:
	.string "Rhyos: I need you two to guard the\n"
	.string "entrance.\p"
	.string "Do your job good for once in your\n"
	.string "damn life...$"

BlocksCaveEntranceLeft:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BlocksCaveEntranceRight:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

AntiquityCity_Text_GruntGuardsPrepareToBattleFemale:
	.string "You have no reason being here kid, so\n"
	.string "leave before we force you.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GRAY} How about no...\p"
	.string "I need to get through and your blocking my way.\p"
	.string "Grunt 2: So we have to force you huh?\n"
	.string "Grunt 1: Good since I've been looking for a\l"
	.string "battle all day.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GRAY} Let's go then!$"

AntiquityCity_Text_GruntGuardsPrepareToBattleMale:
	.string "You have no reason being here kid, so\n"
	.string "leave before we force you.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY} Why should I?\p"
	.string "Instead, how about you move before I\n"
	.string "have to force you to move.\p"
	.string "Grunt 2: You? Force Us? Nice joke kid\n"
	.string "Grunt 1: I'd like to see you try since\l"
	.string "I've been looking for a battle all day.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY} En Garde, Criminals!$"
	
AntiquityCity_Text_Grunt1_Defeated:
	.string "I-I actually was defeated...$"

AntiquityCity_Text_Grunt1_Lost:
	.string "Grunt 1:I-I lost...\p"
	.string "I demand a rematch you little shit!\p"
	.string "{PLAYER}: You just suck.\n"
	.string "Accept it...\p"
	.string "Grunt 2: You may have beat her but I\n"
	.string "won't be so easy to beat.\p"
	.string" {PLAYER}: Yeah ight...$"

AntiquityCity_Text_Grunt2_Defeated:
	.string "No Way!\n"
	.string "Me too!?$"

AntiquityCity_Text_Grunt2_Lost:
	.string "Grunt 2: There's no way we both lost...\p"
	.string "Fine we'll move for now but if you\n"
	.string "run into our bosses prepare for a\l"
	.string "world of trouble kid.\p"
	.string "I'll beat them as easily as I did you.$"
	
Grunt1Moves:
	walk_down
	walk_down
	walk_left
	face_right
	step_end

Grunt2Moves:
	walk_down
	walk_down
	walk_right
	face_left
	step_end

PlayerBacksAwayFromGrunts:
	lock_facing_direction
	walk_down
	walk_down
	unlock_facing_direction
	step_end

AntiquityCity_Text_PlayerTauntsGruntsFemale:
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GRAY} If Roy was here, he'll say\n"
	.string "something like your shit at Pokemon battles and\l"
	.string "Get good you fucking scumbags.\p"
	.string "Grunt 1: ...\n"
	.string "Grunt 2: ...\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY}: That worked wonders huh?$"

AntiquityCity_Text_PlayerTauntsGruntsMale:
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY} Imagine talking shit and 1v1ing\n"
	.string "someone and losing not once but TWICE!\l"
	.string "Get good you fucking scumbags.\p"
	.string "Grunt 1: ...\n"
	.string "Grunt 2: ...\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GRAY}: Quiet now huh?$"
	
	
AntiquityCity_Text_OldPlasmaMember:
	.string "I still can't believe I lost against\n"
	.string "a runt.\p"
	.string "I used to be apart of the greatest evil\n"
	.string "organization, Team Fucking Plasma.$"

AntiquityCity_Text_OldGalacticMember:
	.string "You don't deserve to celebrate since\n"
	.string "I let you win.\p"
	.string "After all, I used to be apart of the world\n"
	.string "changing evil organization, Team Goddamn\l"
	.string "Galactic.$"