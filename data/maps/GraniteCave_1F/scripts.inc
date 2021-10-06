GraniteCave_1F_MapScripts::
	.byte 0
	
GraniteCave_1F_EventScript_Hiker:: @ 822DA5E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM05
	setflag FLAG_RECEIVED_HM05
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash:: @ 822DA8A
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo: @ 822DA94
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash: @ 822DBB7
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DESSATA's POKéMON GYM.$"

GraniteCave_1F_EventScript_Byron::
	lockall
	goto_if_set FLAG_BADGE02_GET, GraniteCave_1F_EventScript_ByronAndRoark
	msgbox GraniteCave_1F_Text_Introduction, MSGBOX_DEFAULT
	faceplayer
	msgbox GraniteCave_1F_Text_ComeBackAfter, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

GraniteCave_1F_EventScript_ByronAndRoark::
	lockall
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
	msgbox GraniteCave_1F_Text_YourBack,MSGBOX_DEFAULT
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	faceplayer
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox GraniteCave_1F_Text_Introduction, MSGBOX_DEFAULT
	delay 40
	msgbox GraniteCave_1F_Text_ImBackDad, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 3, RoarkAppears
	waitmovement 0
	applymovement 4, Common_Movement_FacePlayer
	applymovement 3, Common_Movement_FacePlayer
	waitmovement 0
	msgbox GraniteCave_1F_Text_ByronAndRoarkBattles, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BYRON_AND_ROARK, GraniteCave_1F_Text_ByronAndRoarkDefeat
	goto GraniteCave_1F_EventScript_ByronAndRoarkAcceptsDefeat
	end
	
GraniteCave_1F_EventScript_ByronAndRoarkAcceptsDefeat::
	msgbox GraniteCave_1F_Text_ByronAndRoarkAcceptsDefeat, MSGBOX_DEFAULT
	applymovement 3, RoarkGetsBackToWork
	waitmovement 0
	releaseall
	end

RoarkAppears:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

RoarkGetsBackToWork:
	walk_left
	face_down
	step_end

GraniteCave_1F_Text_Introduction:
	.string "My Name's Byron, Ex-Leader of Canalave\n"
	.string "City Gym in Sinnoh.\p"
	.string "My son, Roark, heard from Steven Stone that\n"
	.string "this cave is a good place to mine for\l"
	.string "extremely rare stones so we decided\p"
	.string "to come here as a father-son vacation.\l"
	.string "...\p"
	.string "Since you look like an aspiring trainer\n"
	.string "how about battling so I can see how\l"
	.string "good you are.$"

GraniteCave_1F_Text_ComeBackAfter:
	.string "You don't have the 2nd badge yet?\p"
	.string "I know how strong Thera is so come\n"
	.string "back after actually beating her.$"

GraniteCave_1F_Text_YourBack:
	.string "...\p"
	.string "I see you're finally back Roark.\n"
	.string "Now get back to mining.\p"
	.string "...\n"
	.string "...\p"
	.string "Roark??$"

GraniteCave_1F_Text_ImBackDad:
	.string "I'm back dad!$"

GraniteCave_1F_Text_ByronAndRoarkBattles:
	.string "Roark: It took longer than expected since\n"
	.string "Thera knows she can talk someone's\l"
	.string "ears off.\p"
	.string "Byron: I see you're finally back Roark.\n"
	.string "We have a trainer here who wants to\l"
	.string "see how it feels to battle a Sinnoh\p"
	.string "Gym Leader.\p"
	.string "Roark: Alright kid, be prepared to face\n"
	.string "the wrath of our Steel/Rock Pokémon!!$"

GraniteCave_1F_Text_ByronAndRoarkDefeat:
	.string "Byron: Hmm...\n"
	.string "Roark: I guess we lost...$"

GraniteCave_1F_Text_ByronAndRoarkAcceptsDefeat:
	.string "Byron: Now get back to mining.$"
	
	
