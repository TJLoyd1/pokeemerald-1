AntiquityCity_MapScripts::
	.byte 0

AntiquityCity_EventScript_NoGood_Flagset::
	goto_if_set FLAG_BADGE01_GET, AntiquityCity_EventScript_UptoNoGood
	release
	end

AntiquityCity_EventScript_UptoNoGood::
	lockall
	setvar VAR_CAMERA_MOVEMENT_TEST, 1
	clearflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	addobject 4
	addobject 5
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MovetoObsidianAdminsTalking
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, 1
	applymovement 4, RhyosLooksatMettao
	waitmovement 0
	msgbox AntiquityCity_Text_Rhyos_Speaking, MSGBOX_DEFAULT
	closemessage
	msgbox AntiquityCity_Text_Mettao_Speaking, MSGBOX_DEFAULT
	closemessage
	msgbox AntiquityCity_Text_LetsGetThisOverWith, MSGBOX_DEFAULT
	closemessage
	applymovement 4, EntersCave
	applymovement 5, EntersCave
	waitmovement 0
	fadescreen 1
	removeobject 4
	removeobject 5
	fadescreen 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	setflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
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
	clearflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	addobject 4
	addobject 5
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MovetoObsidianAdminsTalking2
	waitmovement 0
	applymovement 4, RhyosLooksatMettao
	waitmovement 0
	msgbox AntiquityCity_Text_Rhyos_Speaking, MSGBOX_DEFAULT
	closemessage
	msgbox AntiquityCity_Text_Mettao_Speaking, MSGBOX_DEFAULT
	closemessage
	msgbox AntiquityCity_Text_LetsGetThisOverWith, MSGBOX_DEFAULT
	closemessage
	applymovement 4, EntersCave
	applymovement 5, EntersCave
	waitmovement 0
	fadescreen 1
	removeobject 4
	removeobject 5
	fadescreen 0
	applymovement OBJ_EVENT_ID_CAMERA, MoveBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	setflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	msgbox AntiquityCity_Text_FeelLikeSomeone, MSGBOX_DEFAULT
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
	msgbox AntiquityCity_Text_Brittlebones, MSGBOX_DEFAULT
	checkitem ITEM_TM62, 1
	compare VAR_RESULT, 1
	goto_if_ge AntiquityCity_EventScript_BadMemory
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