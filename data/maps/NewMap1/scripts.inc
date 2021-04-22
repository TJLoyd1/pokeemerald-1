NewMap1_MapScripts::
	.byte 0

NewMap1_EventScript_Sign1::
	msgbox NewMap1_Text_Almost, MSGBOX_SIGN
	release
	end
	
NewMap1_Script_Sign2::
	msgbox NewMap1_Text_Stones, MSGBOX_SIGN
	end
	
NewMap1_EventScript_Stone_Seller::
	lock
	faceplayer
	message Text_StoneSellerGreeting
	waitmessage
	pokemart Pokemart_StoneSale
	msgbox Text_StoneSellerEnd, MSGBOX_DEFAULT
	release
	end
	
	.align 2
Pokemart_StoneSale:
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_STRANGE_SOUVENIR
	.2byte ITEM_NONE
	release
	end
	
Text_StoneSellerGreeting:
	.string "Hey there. If you need a\n"
	.string "evolutionary stone or those new\l"
	.string "strange Sovenirs, I got'em!$"

Text_StoneSellerEnd:
	.string "'Member to come shop with\n"
	.string "ya boy again if you need them stones.$"

NewMap1_Text_Almost:
	.string "TRAINER TIPS\p"
	.string "Tms now have an infinite amount of usage\n"
	.string "unlike a few years ago, where they had\l"
	.string "a one-time use.$"
	
NewMap1_Text_Stones:
	.string "Come this way for some good ole\n"
	.string "stones..yep just stones and a rare\n"
	.string "item from Alola.\n"
	.string "Aww yea head DOWN to find me.$"	