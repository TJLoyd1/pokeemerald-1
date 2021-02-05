MauvilleCity_BikeShop_MapScripts:: @ 820EBBB
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel:: @ 820EBBC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AreYouLikingTheBike
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
MauvilleCity_BikeShop_EventScript_SkipGreeting:
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_YesFar
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_BikeShop_EventScript_NotFar
	release
	end

MauvilleCity_BikeShop_EventScript_NotFar:: @ 820EC3D
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar:: @ 820EC4A
	msgbox MauvilleCity_BikeShop_Text_GuessYouDoNeedBike, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BIKE
	giveitem ITEM_MACH_BIKE
	msgbox MauvilleCity_BikeShop_Text_AboutBikes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_AreYouLikingTheBike::
	msgbox MauvilleCity_BikeShop_Text_AreYouLikingTheBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_Assistant:: @ 820ED31
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook:: @ 820ED3A
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage:: @ 820ED46
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, 0
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_MachBikeMode
	case 1, MauvilleCity_BikeShop_EventScript_HowToRide
	case 2, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 3, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 4, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_MachBikeMode::
	message MauvilleCity_BikeShop_Text_AboutMachBikeMode
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToRide:: @ 820ED88
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn:: @ 820ED94
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes:: @ 820EDA0
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook:: @ 820EDAC
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook:: @ 820EDAE
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage:: @ 820EDBA
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, 0
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_AcroBikeMode
	case 1, MauvilleCity_BikeShop_EventScript_Wheelies
	case 2, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 3, MauvilleCity_BikeShop_EventScript_Jumps
	case 4, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_AcroBikeMode::
	message MauvilleCity_BikeShop_Text_AboutAcroBikeMode
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Wheelies:: @ 820EDFC
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops:: @ 820EE08
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps:: @ 820EE14
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook:: @ 820EE20
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting: @ 820EE22
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me RYDEL.\n"
	.string "I'm the owner of this cycle shop.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway: @ 820EE99
	.string "RYDEL: Your RUNNING SHOES…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike: @ 820EEE8
	.string "RYDEL: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my BIKES.$"

MauvilleCity_BikeShop_Text_GuessYouDoNeedBike: @ 820EF32
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!$"

MauvilleCity_BikeShop_Text_AboutBikes:
	.string "This is my latest BIKE model.\p"
	.string "I poured my heart, my soul, and\n"
	.string "all the knowledge that I gathered\l"
	.string "during my travels on a cold region\l"
	.string "located in the far south.\p"
	.string "My BIKES, just like the ones there,\n"
	.string "can accomplish many different tasks!\p"
	.string "By default, they're set to what\n"
	.string "I call the MACH BIKE MODE.\p"
	.string "In this mode, the BIKE will prioritize\n"
	.string "speed over movement control.\p"
	.string "Then there is the ACRO BIKE MODE,\n"
	.string "which as you may have guessed, trades\l"
	.string "speed in favor of control!\p"
	.string "As a result, this mode allows you\n"
	.string "to perform many different tricks\l"
	.string "using the BIKE!\p"
	.string "I hope you enjoy using it, as much\n"
	.string "as I enjoyed making it!$"

MauvilleCity_BikeShop_Text_AreYouLikingTheBike:
	.string "RYDEL: So, are you liking my BIKE?\n"
	.string "My BIKES are the best ones around!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack: @ 820F3C3
	.string "I'm learning about BIKES while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "BIKE, there're a couple handbooks in\l"
	.string "the back.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage: @ 820F445
	.string "It's a handbook on the BIKE.\n"
	.string "The cover says “MACH BIKE MODE”.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_AboutMachBikeMode:
	.string "The MACH BIKE MODE is the default\n"
	.string "function mode of the BIKE.\p"
	.string "In this state, it prioritizes\n"
	.string "speed over movability.\p"
	.string "To change MODES you just have\n"
	.string "to press the R BUTTON while\l"
	.string "you're standing still.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike: @ 820F487
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike: @ 820F550
	.string "A MACH BIKE is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_SandySlopes: @ 820F61A
	.string "There are small sandy slopes\n"
	.string "throughout the HOENN region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you have a MACH BIKE, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage: @ 820F6ED
	.string "It's a handbook on the BIKE.\n"
	.string "The cover says “ACRO BIKE MODE”.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_AboutAcroBikeMode:
	.string "The ACRO BIKE MODE is the second\n"
	.string "function mode of the BIKE.\p"
	.string "In this state, it trades speed\n"
	.string "to prioritize movability.\p"
	.string "To change MODES you just have\n"
	.string "to press the R BUTTON while\l"
	.string "you're standing still.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Wheelies: @ 820F72F
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_BunnyHops: @ 820F7F5
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps: @ 820F898
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"

