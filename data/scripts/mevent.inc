EventScript_Questionnaire:: @ 827381B
	lockall
	msgbox Mevent_Text_FillOutQuestionnaire, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Mevent_EventScript_Release
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUESTIONNAIRE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartEmployeeObjectEventId
	compare VAR_0x8004, 1
	goto_if_eq Mevent_EventScript_PlayerInputMysteryEventPhrase
	compare VAR_0x8004, 2
	goto_if_eq Mevent_EventScript_PlayerInputMysteryGiftPhrase
	compare VAR_0x8004, 3
	goto_if_eq Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase
	compare VAR_RESULT, 0
	goto_if_eq Mevent_EventScript_Release
	compare VAR_RESULT, 1
	goto_if_eq Mevent_EventScript_QuestionnaireThankYou
	end

Mevent_EventScript_PlayerInputMysteryEventPhrase:: @ 827386D
	goto_if_unset FLAG_SYS_POKEDEX_GET, Mevent_EventScript_QuestionnaireThankYou
	goto_if_set FLAG_SYS_MYSTERY_EVENT_ENABLE, Mevent_EventScript_QuestionnaireThankYou
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox Mevent_Text_YouKnowThoseWordsEvent, MSGBOX_DEFAULT
	setflag FLAG_SYS_MYSTERY_EVENT_ENABLE
	msgbox Mevent_Text_YouCanAccessMysteryEvent, MSGBOX_DEFAULT
	releaseall
	end

Mevent_EventScript_PlayerInputMysteryGiftPhrase:: @ 82738B5
	goto_if_unset FLAG_SYS_POKEDEX_GET, Mevent_EventScript_QuestionnaireThankYou
	goto_if_set FLAG_SYS_MYSTERY_GIFT_ENABLE, Mevent_EventScript_QuestionnaireThankYou
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox Mevent_Text_YouKnowThoseWordsGift, MSGBOX_DEFAULT
	setflag FLAG_SYS_MYSTERY_GIFT_ENABLE
	msgbox Mevent_Text_YouCanAccessMysteryGift, MSGBOX_DEFAULT
	releaseall
	end

Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase::
	goto_if_unset FLAG_BADGE05_GET, Mevent_EventScript_QuestionnaireThankYou
	goto_if_unset FLAG_SYS_POKEDEX_GET, Mevent_EventScript_QuestionnaireThankYou
	goto_if_set FLAG_RECEIVED_FIRST_BONUS, Mevent_EventScript_QuestionnaireThankYou
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox Mevent_Text_YouAreTheChosenOne, MSGBOX_DEFAULT
@ Give the Player a Hoenn starter based on the one they chose:
	switch VAR_STARTER_MON
	case 0, Mevent_EventScript_ReceiveMudkip
	case 1, Mevent_EventScript_ReceiveTreecko
	case 2, Mevent_EventScript_ReceiveTorchic

Mevent_EventScript_ReceiveMudkip:
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq Mevent_EventScript_SendBonusToParty
	compare VAR_RESULT, 1
	goto_if_eq Mevent_EventScript_SendBonusToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	goto Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase_End
Mevent_EventScript_ReceiveTreecko:
	setvar VAR_TEMP_1, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq Mevent_EventScript_SendBonusToParty
	compare VAR_RESULT, 1
	goto_if_eq Mevent_EventScript_SendBonusToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	goto Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase_End
Mevent_EventScript_ReceiveTorchic:
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq Mevent_EventScript_SendBonusToParty
	compare VAR_RESULT, 1
	goto_if_eq Mevent_EventScript_SendBonusToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	goto Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase_End

Mevent_EventScript_SendBonusToParty::
	call Mevent_EventScript_ReceivedBonusFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase_End
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase_End
	end
Mevent_EventScript_SendBonusToPC::
	call Mevent_EventScript_ReceivedBonusFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Mevent_EventScript_BonusTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Mevent_EventScript_BonusTransferredToPC
	end

Mevent_EventScript_ReceivedBonusFanfare::
	switch VAR_STARTER_MON
	case 0, Mevent_EventScript_BufferMudkip
	case 1, Mevent_EventScript_BufferTreecko
	case 2, Mevent_EventScript_BufferTorchic
Mevent_EventScript_BufferMudkip:
	bufferspeciesname 1, SPECIES_MUDKIP
	playfanfare MUS_FANFA4
	message Mevent_Text_ObtainedMudkip
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MUDKIP
	return
Mevent_EventScript_BufferTreecko:
	bufferspeciesname 1, SPECIES_TREECKO
	playfanfare MUS_FANFA4
	message Mevent_Text_ObtainedTreecko
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TREECKO
	return
Mevent_EventScript_BufferTorchic:
	bufferspeciesname 1, SPECIES_TORCHIC
	playfanfare MUS_FANFA4
	message Mevent_Text_ObtainedTorchic
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TORCHIC
	return

Mevent_EventScript_BonusTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase_End
	end

Mevent_EventScript_PlayerInputQuestionnaireBonus1Phrase_End:
	setflag FLAG_RECEIVED_FIRST_BONUS
	msgbox Mevent_Text_WereDoneHere, MSGBOX_DEFAULT
	releaseall
	end

Mevent_EventScript_Release:: @ 82738FD
	releaseall
	end

Mevent_EventScript_QuestionnaireThankYou:: @ 82738FF
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	msgbox Mevent_Text_QuestionnaireThankYou, MSGBOX_DEFAULT
	releaseall
	end
