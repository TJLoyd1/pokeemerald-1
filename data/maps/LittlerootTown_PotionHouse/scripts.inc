LittlerootTown_PotionHouse_MapScripts::
	.byte 0

LittlerootTown_House4_Script_FirstAdventure::
	lock
	faceplayer
	msgbox Text_JourneyStarts, MSGBOX_DEFAULT
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 1
	goto_if_ge Script_HasPotionsAlready2
	msgbox Text_GivingPotion2, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 1
	compare VAR_RESULT, 0
	goto_if_eq Script_BagIsFull3
	release
	end

Script_HasPotionsAlready2::
	msgbox Text_HasPotionsAlready2, MSGBOX_DEFAULT
	release
	end

Script_BagIsFull3::
	msgbox Text_BagIsFull3, MSGBOX_DEFAULT
	release
	end

LittlerootTown_House4_Script_Smallgirl::
	lock
	faceplayer
	msgbox Text_Smallgirl, MSGBOX_DEFAULT
	release
	end

Text_JourneyStarts:
	.string "You are just now starting your journey...\n"
	.string "This should be useful for you.$"

Text_GivingPotion2:
	.string "One Potion just for you sweetie.$"

Text_HasPotionsAlready2:
	.string "I remember when i first started, Potions\n"
	.string "were so useful back then.$"

Text_BagIsFull3:
	.string "Your BAG is full.$"

Text_Smallgirl:
	.string "Hi!\n"
	.string "I can't wait to start my journey\l"
	.string "just like you and Mommy, {PLAYER}!$"