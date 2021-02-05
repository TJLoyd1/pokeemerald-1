OldaleGrotto_MapScripts::
	.byte 0

OldaleGrotto_EventScript_Camper::
	msgbox OldaleGrotto_Text_RarePokémon, MSGBOX_NPC
	end

OldaleGrotto_EventScript_GrottoSign::
	msgbox OldaleGrotto_Text_GrottoSign, MSGBOX_SIGN
	end

OldaleGrotto_End_EventScript_CHIKORITA::
	lockall
	waitse
	playmoncry SPECIES_CHIKORITA, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_CHIKORITA, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq OldaleGrotto_End_EventScript_DefeatedChikorita
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq OldaleGrotto_End_EventScript_RanFromChikorita
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq OldaleGrotto_End_EventScript_RanFromChikorita
	setflag FLAG_DEFEATED_SUDOWOODO
	releaseall
	end

OldaleGrotto_End_EventScript_DefeatedChikorita:: @ 823B155
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

OldaleGrotto_End_EventScript_RanFromChikorita:: @ 823B163
	setvar VAR_0x8004, SPECIES_CHIKORITA
	goto Common_EventScript_NopReturn
	end

OldaleGrotto_Text_RarePokémon:
	.string "I came here because I heard there was\n"
	.string "a extremely rare Pokémon here.\l"
	.String "I wonder where it is.$"

OldaleGrotto_Text_GrottoSign:
	.string "Oldale Grotto"
	.string "{LEFT_ARROW} OLDALE TOWN$"