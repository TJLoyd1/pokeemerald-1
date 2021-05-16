OldaleGrotto_MapScripts::
	.byte 0

OldaleGrotto_EventScript_GrottoSign::
	msgbox OldaleGrotto_Text_GrottoSign, MSGBOX_SIGN
	end

OldaleGrotto_End_EventScript_CHIKORITA::
	lockall
	waitse
	playmoncry SPECIES_CHIKORITA, 0
	msgbox OldaleGrotto_End_Text_ChikoritaCry, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_CHIKORITA, 10, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
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

OldaleGrotto_End_Text_ChikoritaCry:
	.string "Chikkoo!$"

OldaleGrotto_Text_GrottoSign:
	.string "Oldale Grotto"
	.string "{LEFT_ARROW} OLDALE TOWN$"

OldaleGrotto_EventScript_Camper::
	msgbox OldaleGrotto_Text_RarePokemon, MSGBOX_NPC
	end

OldaleGrotto_Text_RarePokemon:
	.string "I heard there is a rare Pokemon around\n"
	.string "Oldale Grotto, so I came to look but\l"
	.string "it seems that rumor was wrong.$"