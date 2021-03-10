.set LOCALID_FOSSIL, 1

DesertUnderpass_MapScripts:: @ 823AF37
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition: @ 823AF3D
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil:: @ 823AF41
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil:: @ 823AF57
	checkitemspace ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, FALSE
	call_if_eq Common_EventScript_ShowBagIsFull
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveRootFossil:: @ 823AF68
	checkitemspace ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, FALSE
	call_if_eq Common_EventScript_ShowBagIsFull
	giveitem ITEM_ROOT_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end
