AntiquityCity_MapScripts::
	.byte 0

Script_ItemDemonstration::
	lock
	faceplayer
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	checkitem ITEM_RARE_CANDY, 999
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
	checkitem ITEM_RARE_CANDY, 999
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

AntiquityCity_EventScript_Sign1::
	msgbox AntiquityCity_Text_Sure, MSGBOX_SIGN
	release
	end

AntiquityCity_EventScript_Camper::
	msgbox AntiquityCity_Text_FromTheWoods, MSGBOX_NPC
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

AntiquityCity_Text_Sure:
	.string "Enter at your own risk because\n"
	.string "you will get bombarded by the\l"
	.string "Devs of this game, so be CAREFUL.$"

AntiquityCity_Text_FromTheWoods:
	.string "I was just in Petalburg Woods looking\n"
	.string "for my girlfriend, but I couldn't\l"
	.string "find her.$"