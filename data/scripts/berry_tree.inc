BerryTreeScript:: @ 82742F9
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_Sparkling:: @ 827434F
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil:: @ 8274359
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	compare VAR_RESULT, TRUE
	goto_if_eq BerryTree_EventScript_WantToPlant
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_WantToPlant:: @ 8274374
	msgbox BerryTree_Text_WantToPlant, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_ChooseBerryToPlant
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_CancelPlanting
	end

BerryTree_EventScript_ChooseBerryToPlant:: @ 8274393
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseBerry
	waitstate
	compare VAR_ITEM_ID, 0
	goto_if_eq BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_PlantBerry

BerryTree_EventScript_CancelPlanting:: @ 82743AF
	release
	end

BerryTree_EventScript_CheckBerryStage1:: @ 82743B1
	lockall
	special ObjectEventInteractionGetBerryCountString
	checkitem ITEM_WAILMER_PAIL, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage2:: @ 82743C1
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage3:: @ 82743D1
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage4:: @ 82743E1
	call BerryTree_EventScript_GetCareAdverb
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_WAILMER_PAIL, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb:: @ 82743F6
	compare VAR_0x8005, 0
	goto_if_eq BerryTree_EventScript_SetAdverbPoor
	compare VAR_0x8005, 4
	goto_if_eq BerryTree_EventScript_SetAdverbGreat
	bufferstring 1, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat:: @ 8274413
	bufferstring 1, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor:: @ 827441A
	bufferstring 1, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown:: @ 8274421
	buffernumberstring 1, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_PickBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_CancelPickingBerry

BerryTree_EventScript_PickBerry:: @ 8274448
	special ObjectEventInteractionPickBerryTree
	compare VAR_0x8004, 0
	goto_if_eq BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	release
	end

BerryTree_EventScript_BerryPocketFull:: @ 8274470
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_CancelPickingBerry:: @ 8274479
	message BerryTree_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry:: @ 8274482
	lockall
	special ObjectEventInteractionGetBerryTreeData
	call BerryTree_EventScript_PlantBerry
	releaseall
	end

BerryTree_EventScript_DontWater:: @ 82744BE
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail:: @ 82744C0
	special ObjectEventInteractionGetBerryTreeData
	lockall
BerryTree_EventScript_WaterBerry:: @ 82744C4
	special ObjectEventInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
	releaseall
	end

BerryTree_EventScript_PlantBerry:: @ 82744DD
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_PlantedOneBerry, MSGBOX_DEFAULT
	return

BerryTree_Text_ItsSoftLoamySoil: @ 82744F0
	.string "It's soft, loamy soil.$"

BerryTree_Text_WantToPlant: @ 8274507
	.string "It's soft, loamy soil.\n"
	.string "Want to plant a BERRY?$"

BerryTree_Text_PlantedOneBerry: @ 8274535
	.string "{PLAYER} planted one {STR_VAR_1} in\n"
	.string "the soft, loamy soil.$"

BerryTree_Text_BerryGrowthStage1: @ 8274560
	.string "One {STR_VAR_1} was planted here.\n"
	.string "Want to water it with the WAILMER PAIL?$"

BerryTree_Text_BerryGrowthStage2: @ 8274579
	.string "This {STR_VAR_1} plant has sprouted.\n"
	.string "Want to water it with the WAILMER PAIL?$"

BerryTree_Text_BerryGrowthStage3: @ 827458A
	.string "This {STR_VAR_1} plant is growing taller.\n"
	.string "Want to water it with the WAILMER PAIL?$"

BerryTree_Text_BerryGrowthStage4: @ 82745AB
	.string "These {STR_VAR_1} flowers are blooming\n"
	.string "{STR_VAR_2}.\p"
	.string "Want to water them with\n"
	.string "the WAILMER PAIL?$"

BerryTree_Text_CareAdverbGreat: @ 82745CD
	.string "very beautifully$"

BerryTree_Text_CareAdverbPoor: @ 82745DE
	.string "cutely$"

BerryTree_Text_CareAdverbGood: @ 82745E5
	.string "prettily$"

BerryTree_Text_WantToPick: @ 82745EE
	.string "You found {STR_VAR_2} {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"

BerryTree_Text_PickedTheBerry: @ 827461B
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"

BerryTree_Text_BerryPocketFull: @ 827468F
	.string "The BAG's BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"

BerryTree_Text_BerryLeftUnpicked: @ 82746CB
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "unpicked.$"

BerryTree_Text_ExclamationPoint: @ 8274744
	.string "!$"
