DewfordTown_PokemonMart_MapScripts::
	.byte 0

DewfordTown_PokemonMart_EventScript_Clerk:: @ 81FC240
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE02_GET, DewfordTown_PokemonMart_ExpandedItems
	pokemart DewfordTown_PokemonMart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

DewfordTown_PokemonMart_Pokemart_Basic: @ 81FC260
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ETHER
	.2byte ITEM_NONE
	release
	end

DewfordTown_PokemonMart_ExpandedItems:: @ 81FC26C
	pokemart DewfordTown_PokemonMart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
DewfordTown_PokemonMart_Pokemart_Expanded: @ 81FC27C
	.2byte ITEM_POKE_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_ETHER
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

DewfordTown_PokemonMart_EventScript_Man::
	msgbox DewfordTown_PokemonMart_Text_NewMart, MSGBOX_NPC
	closemessage
	release
	end

DewfordTown_PokemonMart_Text_NewMart:
	.string "It's about time they opened a new\n"
	.string "PokeMart in Dewford Town.$"