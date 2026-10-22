/*
older system, from older script
*/
#define DIALOG_SLASHREFUNDME	4600
new refundLevel[ MAX_PLAYERS ] = { 1, ... }, refundMaterials[ MAX_PLAYERS ] = { 0, ... }, refundArmsDealerSkill[ MAX_PLAYERS ] = { 0, ... }, refundCarJackerSkill[ MAX_PLAYERS ] = { 0, ... },
	refundDetectiveSkill[ MAX_PLAYERS ] = { 0, ... }, refundLawyerSkill[ MAX_PLAYERS ] = { 0, ... }, refundMechanicSkill[ MAX_PLAYERS ] = { 0, ... }, refundDrugDealerSkill[ MAX_PLAYERS ] = { 0, ... },
	refundSexSkill[ MAX_PLAYERS ] = { 0, ... }, refundBoxingSkill[ MAX_PLAYERS ] = { 0, ... }, refundFishingSkill[ MAX_PLAYERS ] = { 0, ... }, refundPizzaSkill[ MAX_PLAYERS ] = { 0, ... }, 
	refundBusSkill[ MAX_PLAYERS ] = { 0, ... }, refundCannabis[ MAX_PLAYERS ] = { 0, ... }, refundCocaine[ MAX_PLAYERS ] = { 0, ... }, refundMeth[ MAX_PLAYERS ] = { 0, ... }, 
	refundXanax[ MAX_PLAYERS ] = { 0, ... }, refundPromethazine[ MAX_PLAYERS ] = { 0, ... }, refundCodeine[ MAX_PLAYERS ] = { 0, ... }, refundLean[ MAX_PLAYERS ] = { 0, ... },
	refundPlayingHours[ MAX_PLAYERS ] = { 2, ... }, refundHealthUpgrade[ MAX_PLAYERS ] = { 0, ... }, refundArmorUpgrade[ MAX_PLAYERS ] = { 0, ... }, 
	refundEditingRefund[ MAX_PLAYERS ] = { INVALID_PLAYER_ID, ... }, bool:refundPlayerAllowed[ MAX_PLAYERS ] = { false, ... }, bool:refundPlayerAwaitingRefund[ MAX_PLAYERS ] = { false, ... };
ShowPlayerRefundDialog( playerid, giveplayerid ){
	if( giveplayerid != playerid ) refundEditingRefund[ playerid ] = giveplayerid;
	new refundStr[ 5000 ];
	format( refundStr, sizeof( refundStr ), "Refund\t\t\tAmount" );
	format( refundStr, sizeof( refundStr ), "%s\n|=|REFUND|=|\nLevel\t\t\t%d\
											   \nMaterials\t\t\t%d\
											   \nArmsDealerSkill\t\t%d\
											   \nCarJackerSkill\t\t%d\
											   \nDetectiveSkill\t\t%d\
											   \nLawyerSkill\t\t%d\
											   \nMechanicSkill\t\t%d\
											   \nDrugDealerSkill\t\t%d\
											   \nSexSkill\t\t\t%d\
											   \nBoxingSkill\t\t%d\
											   \nFishingSkill\t\t%d\
											   \nPizzaSkill\t\t\t%d\
											   \nBusSkill\t\t\t%d\
											   \nCannabis\t\t\t%d\
											   \nCocaine\t\t\t%d\
											   \nMeth\t\t\t%d\
											   \nXanax\t\t\t%d\
											   \nPromethazine\t\t%d\
											   \nCodeine\t\t\t%d\
											   \nLean\t\t\t%d\n\
											   \nPlayingHours\t\t%d\
											   \nHealthUpgrade\t\t%d\
											   \nArmorUpgrade\t\t%d\
											   \n\tSend Refund Request", refundStr, refundLevel[ giveplayerid ], refundMaterials[ giveplayerid ], refundArmsDealerSkill[ giveplayerid ], refundCarJackerSkill[ giveplayerid ],
											    refundDetectiveSkill[ giveplayerid ], refundLawyerSkill[ giveplayerid ], refundMechanicSkill[ giveplayerid ], refundDrugDealerSkill[ giveplayerid ], refundSexSkill[ giveplayerid ],
											    refundBoxingSkill[ giveplayerid ], refundFishingSkill[ giveplayerid ], refundPizzaSkill[ giveplayerid ], refundBusSkill[ giveplayerid ], refundCannabis[ giveplayerid ], 
											    refundCocaine[ giveplayerid ], refundMeth[ giveplayerid ], refundXanax[ giveplayerid ], refundPromethazine[ giveplayerid ], refundCodeine[ giveplayerid ], refundLean[ giveplayerid ],
											    refundPlayingHours[ giveplayerid ], refundHealthUpgrade[ giveplayerid ], refundArmorUpgrade[ giveplayerid ] );
	return ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME, DIALOG_STYLE_TABLIST_HEADERS, "Refund-Me Dialog", refundStr, "Select", "Cancel" );
}
CMD:refundme( playerid ){
	if( !refundPlayerAllowed[ playerid ] || refundPlayerAwaitingRefund[ playerid ] ) return SendClientMessage( playerid, -1, "{ff0000}Error:{ffffff} Contact a head admin+ to use /allowrefund command on you." );
	else ShowPlayerRefundDialog( playerid, playerid );
	return ( true );
}
CMD:editrefund( playerid, params[ ] ){
	new giveplayerid;
	if( PlayerInfo[ playerid ] [ pAdmin ] < 1337 ) return AdmErrorMsg;
	else if( sscanf( params, "u", giveplayerid ) ) return SendClientMessage( playerid, -1, "Usage: /editrefund [ID/Name]" );
	else if( !IsPlayerConnected( giveplayerid ) ) return SendClientMessage( playerid, -1, "Invalid player id!" );
	else{
		ShowPlayerRefundDialog( playerid, giveplayerid );
	}
	return 1;
}
CMD:allowrefund( playerid, params[ ] ){
	new giveplayerid;
	if( PlayerInfo[ playerid ] [ pAdmin ] < 1337 ) return AdmErrorMsg;
	else if( sscanf( params, "u", giveplayerid ) ) return SendClientMessage( playerid, -1, "Usage: /allowrefund [ID/Name]" );
	else if( !IsPlayerConnected( giveplayerid ) ) return SendClientMessage( playerid, -1, "Invalid player id!" );
	else{
		va_SendClientMessage( playerid, -1, "You've allowed %s(%d) to use /refundme", PlayerOOCName( giveplayerid ), giveplayerid );
		ShowPlayerDialog( giveplayerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Refund", "An admin has allowed you to use /refundme.\n\
																				   Lying may result in a ban!\n\
																				   When you are done, select the 'Send Refund Request'.\n\
																				   The command is /refundme. ", "Close", "" );
		refundPlayerAllowed[ giveplayerid ] = true;
	}
	return 1;
}
CMD:approverefund( playerid, params[ ] ){
	new giveplayerid, confirm[ 8 ];
	if( PlayerInfo[ playerid ] [ pAdmin ] < 1337 ) return AdmErrorMsg;
	if( sscanf( params, "us[8]", giveplayerid, confirm ) ) return SendClientMessage( playerid, -1, "Usage: /approverefund [Playerid] [Confirm]" );
	else if( !IsPlayerConnected( giveplayerid ) ) return SendClientMessage( playerid, -1, "That player is not connected!" );
	else if( refundPlayerAllowed[ giveplayerid ] ) return SendClientMessage( playerid, -1, "That player is currently filling their info in /refundme." );
	else if( !refundPlayerAwaitingRefund[ giveplayerid ] ) return SendClientMessage( playerid, -1, "That player is not awaiting for a refund!" );
	else if( equal( confirm, "confirm" ) ){
		RefundPlayer( giveplayerid );
		va_SendClientMessage( playerid, -1, "Successfully refunded %s(%d)", PlayerOOCName( giveplayerid ), giveplayerid );
	}
	return ( true );
}

RefundPlayer( giveplayerid ){
	new lvl;
	PlayerInfo[ giveplayerid ] [ pLevel ] = refundLevel[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pMats ] = refundMaterials[ giveplayerid ];
	if( refundArmsDealerSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundArmsDealerSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundArmsDealerSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundArmsDealerSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundArmsDealerSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pArmsSkill ] = lvl;
	if( refundCarJackerSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundCarJackerSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundCarJackerSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundCarJackerSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundCarJackerSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pJackSkill ] = lvl;
	if( refundDetectiveSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundDetectiveSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundDetectiveSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundDetectiveSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundDetectiveSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pDetSkill ] = lvl;
	if( refundLawyerSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundLawyerSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundLawyerSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundLawyerSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundLawyerSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pLawSkill ] = lvl;
	if( refundMechanicSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundMechanicSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundMechanicSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundMechanicSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundMechanicSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pMechSkill ] = lvl;
	if( refundDrugDealerSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundDrugDealerSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundDrugDealerSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundDrugDealerSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundDrugDealerSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pDrugsSkill ] = lvl;
	if( refundSexSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundSexSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundSexSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundSexSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundSexSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pSexSkill ] = lvl;
	if( refundBoxingSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundBoxingSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundBoxingSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundBoxingSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundBoxingSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pBoxSkill ] = lvl;
	if( refundFishingSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundFishingSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundFishingSkill[ giveplayerid ] == 3 ) lvl = 100;
	else if( refundFishingSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundFishingSkill[ giveplayerid ] >= 5 ) lvl = 400;
	PlayerInfo[ giveplayerid ] [ pFishSkill ] = lvl;
	if( refundPizzaSkill[ giveplayerid ] == 1 ) lvl = 0;
	else if( refundPizzaSkill[ giveplayerid ] == 2 ) lvl = 50;
	else if( refundPizzaSkill[ giveplayerid ] == 3 ) lvl = 120;
	else if( refundPizzaSkill[ giveplayerid ] == 4 ) lvl = 200;
	else if( refundPizzaSkill[ giveplayerid ] >= 5 ) lvl = 270;
	PlayerInfo[ giveplayerid ] [ pPizzaSkill ] = lvl;
	PlayerInfo[ giveplayerid ] [ pCannabis ] = refundCannabis[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pCocaine ] = refundCocaine[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pMeth ] = refundMeth[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pXanax ] = refundXanax[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pPromethazine ] = refundPromethazine[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pCodeine ] = refundCodeine[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pLean ] = refundLean[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pConnectTime ] = refundPlayingHours[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pSHP ] = refundHealthUpgrade[ giveplayerid ];
	PlayerInfo[ giveplayerid ] [ pSHealth ] = refundArmorUpgrade[ giveplayerid ];
	refundPlayerAwaitingRefund[ giveplayerid ] = false;
	SendClientMessage( giveplayerid, -1, "You've been successfully refunded!" );
	new refundStr[ 5000 ];
	format( refundStr, sizeof( refundStr ), "Refund\t\t\tAmount" );
	format( refundStr, sizeof( refundStr ), "%s\nLevel\t\t\t%d\
											   \nMaterials\t\t\t%d\
											   \nArmsDealerSkill\t\t%d\
											   \nCarJackerSkill\t\t%d\
											   \nDetectiveSkill\t\t%d\
											   \nLawyerSkill\t\t%d\
											   \nMechanicSkill\t\t%d\
											   \nDrugDealerSkill\t\t%d\
											   \nSexSkill\t\t\t%d\
											   \nBoxingSkill\t\t%d\
											   \nFishingSkill\t\t%d\
											   \nPizzaSkill\t\t\t%d\
											   \nBusSkill\t\t\t%d\
											   \nCannabis\t\t\t%d\
											   \nCocaine\t\t\t%d\
											   \nMeth\t\t\t%d\
											   \nXanax\t\t\t%d\
											   \nPromethazine\t\t%d\
											   \nCodeine\t\t\t%d\
											   \nLean\t\t\t%d\
											   \nPlayingHours\t\t%d\
											   \nHealthUpgrade\t\t%d\
											   \nArmorUpgrade\t\t%d", refundStr, refundLevel[ giveplayerid ], refundMaterials[ giveplayerid ], refundArmsDealerSkill[ giveplayerid ], refundCarJackerSkill[ giveplayerid ],
											    refundDetectiveSkill[ giveplayerid ], refundLawyerSkill[ giveplayerid ], refundMechanicSkill[ giveplayerid ], refundDrugDealerSkill[ giveplayerid ], refundSexSkill[ giveplayerid ],
											    refundBoxingSkill[ giveplayerid ], refundFishingSkill[ giveplayerid ], refundPizzaSkill[ giveplayerid ], refundBusSkill[ giveplayerid ], refundCannabis[ giveplayerid ], 
											    refundCocaine[ giveplayerid ], refundMeth[ giveplayerid ], refundXanax[ giveplayerid ], refundPromethazine[ giveplayerid ], refundCodeine[ giveplayerid ], refundLean[ giveplayerid ],
											    refundPlayingHours[ giveplayerid ], refundHealthUpgrade[ giveplayerid ], refundArmorUpgrade[ giveplayerid ] );
	ShowPlayerDialog( giveplayerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Successfully refunded", refundStr, "Close", "" );
	new str[ 500 ], IP[ 20 ];
	GetPlayerIp( giveplayerid, IP, sizeof( IP ) );
	gpci( giveplayerid, playerserial, sizeof( playerserial ) );
	format( str, sizeof( str ), "[ %s(%d) REFUNDED ]", PlayerOOCName( giveplayerid ), giveplayerid );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Level: %d", refundLevel[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Materials: %d", refundMaterials[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Arms Dealer Skill: %d", refundArmsDealerSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Car Jacker Skill: %d", refundCarJackerSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Detective Skill: %d", refundDetectiveSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Lawyer Skill: %d", refundLawyerSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Mechanic Skill: %d", refundMechanicSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Drug Dealer Skill: %d", refundDrugDealerSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format(str, sizeof(str), "> Sex Skill: %d", refundSexSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Boxing Skill: %d", refundBoxingSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Fishing Skill: %d", refundFishingSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Pizza Skill: %d", refundPizzaSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Bus Skill: %d", refundBusSkill[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Cannabis: %d", refundCannabis[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Cocaine: %d", refundCocaine[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Meth: %d", refundMeth[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Xanax: %d", refundXanax[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Promethazine: %d", refundPromethazine[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Codeine: %d", refundCodeine[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Lean: %d",  refundLean[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Playing Hours: %d", refundPlayingHours[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Health Upgrade: %d", refundHealthUpgrade[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Armor Upgrade: %d", refundArmorUpgrade[ giveplayerid ] );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> IP: %s", IP );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "> Serial: %s", playerserial );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), "[ %s(%d) REFUNDED ]", PlayerOOCName( giveplayerid ), giveplayerid );
	logswrite( "REFUNDS.refund", str );
	format( str, sizeof( str ), " " );
	logswrite( "REFUNDS.refund", str );
	return ( true );
}

Hook:refund_OnDialogResponse( playerid, dialogid, response, listitem, inputtext[] ){
	switch( dialogid ){
		case DIALOG_SLASHREFUNDME:{
			if( response ){
				switch( listitem ){
					case 0: ShowPlayerRefundDialog( playerid, playerid );
					case 1: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+1, DIALOG_STYLE_INPUT, "Level", "Below type what was your level.", "Select", "Cancel" );
					case 2: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+2, DIALOG_STYLE_INPUT, "Materials", "Below type how many materials you had.", "Select", "Cancel" );
					case 3: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+3, DIALOG_STYLE_INPUT, "Arms Dealer Skill", "Below type what was your arms dealer skill.", "Select", "Cancel" );
					case 4: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+4, DIALOG_STYLE_INPUT, "Car Jacker Skill", "Below type what was your car jacker skill.", "Select", "Cancel" );
					case 5: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+5, DIALOG_STYLE_INPUT, "Detective Skill", "Below type what was your detective skill.", "Select", "Cancel" );
					case 6: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+6, DIALOG_STYLE_INPUT, "Lawyer Skill", "Below type what was your lawyer skill.", "Select", "Cancel" );
					case 7: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+7, DIALOG_STYLE_INPUT, "Mechanic Skill", "Below type what was your mechanic skill.", "Select", "Cancel" );
					case 8: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+8, DIALOG_STYLE_INPUT, "Drug Dealer Skill", "Below type what was your drug dealer skill.", "Select", "Cancel" );
					case 9: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+9, DIALOG_STYLE_INPUT, "Sex Skill", "Below type what was your sex skill.", "Select", "Cancel" );
					case 10: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+10, DIALOG_STYLE_INPUT, "Boxing Skill", "Below type what was your boxing skill.", "Select", "Cancel" );
					case 11: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+11, DIALOG_STYLE_INPUT, "Fishing Skill", "Below type what was your fishing skill.", "Select", "Cancel" );
					case 12: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+12, DIALOG_STYLE_INPUT, "Pizza Skill", "Below type what was your pizza skill.", "Select", "Cancel" );
					case 13: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+13, DIALOG_STYLE_INPUT, "Bus Skill", "Below type what was your bus skill.", "Select", "Cancel" );
					case 14: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+14, DIALOG_STYLE_INPUT, "Cannabis", "Below type how many cannabis you had.", "Select", "Cancel" );
					case 15: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+15, DIALOG_STYLE_INPUT, "Cocaine", "Below type how many cocaine you had.", "Select", "Cancel" );
					case 16: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+16, DIALOG_STYLE_INPUT, "Meth", "Below type how many meth you had.", "Select", "Cancel" );
					case 17: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+17, DIALOG_STYLE_INPUT, "Xanax", "Below type how many xanax you had.", "Select", "Cancel" );
					case 18: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+18, DIALOG_STYLE_INPUT, "Promethazine", "Below type how many promethazine you had.", "Select", "Cancel" );
					case 19: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+19, DIALOG_STYLE_INPUT, "Codeine", "Below type how many codeine you had.", "Select", "Cancel" );
					case 20: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+20, DIALOG_STYLE_INPUT, "Lean", "Below type how many lean you had.", "Select", "Cancel" );
					case 21: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+21, DIALOG_STYLE_INPUT, "Playing Hours", "Below type how many playing hours you had.", "Select", "Cancel" );
					case 22: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+22, DIALOG_STYLE_INPUT, "Health Upgrade", "Below type what was percentage of your health on spawn.", "Select", "Cancel" );
					case 23: ShowPlayerDialog( playerid, DIALOG_SLASHREFUNDME+23, DIALOG_STYLE_INPUT, "Armor Upgrade", "Below type what was percentage of your armor on spawn.", "Select", "Cancel" );
					case 24:{
						new str[ 128 ];
						if( !refundPlayerAwaitingRefund[ playerid ] ){
							SendClientMessage( playerid, -1, "Your refund request has been sent." );
							refundPlayerAllowed[ playerid ] = false;
							format( str, sizeof( str ), "%s(%d) has requested a refund. /editrefund (%d)", PlayerOOCName( playerid ), playerid, playerid );
							ABroadCast( COLOR_LIGHTRED, str, 1337 );
							refundPlayerAwaitingRefund[ playerid ] = true;
						}
					}
				}
			} else ShowPlayerRefundDialog( playerid, playerid ), SendClientMessage(playerid, -1, "You need to press 'send refund request'");
		}
		case DIALOG_SLASHREFUNDME+1:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundLevel[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundLevel[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+2:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundMaterials[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundMaterials[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+3:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundArmsDealerSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundArmsDealerSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+4:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundCarJackerSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundCarJackerSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+5:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundDetectiveSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundDetectiveSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+6:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundLawyerSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundLawyerSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+7:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundMechanicSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundMechanicSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+8:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundDrugDealerSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundDrugDealerSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+9:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundSexSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundSexSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+10:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundBoxingSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundBoxingSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+11:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundFishingSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundFishingSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+12:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundPizzaSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundPizzaSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+13:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundBusSkill[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundBusSkill[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+14:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundCannabis[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundCannabis[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+15:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundCocaine[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundCocaine[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+16:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundMeth[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundMeth[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+17:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundXanax[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundXanax[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+18:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundPromethazine[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundPromethazine[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+19:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundCodeine[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundCodeine[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+20:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundLean[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundLean[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+21:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundPlayingHours[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundPlayingHours[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+22:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundHealthUpgrade[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundHealthUpgrade[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
		case DIALOG_SLASHREFUNDME+23:{
			if( response ){
				if( !IsNumeric( inputtext ) ) return ShowPlayerRefundDialog( playerid, playerid );
				else{
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) refundArmorUpgrade[ refundEditingRefund[ playerid ] ] = strval( inputtext );
					else refundArmorUpgrade[ playerid ] = strval( inputtext );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) ShowPlayerRefundDialog( playerid, refundEditingRefund[ playerid ] );
					else ShowPlayerRefundDialog( playerid, playerid );
					if( refundEditingRefund[ playerid ] != INVALID_PLAYER_ID ) va_SendClientMessage( playerid, -1, "You are currently editing %s(%d)'s refund-status.", PlayerOOCName( refundEditingRefund[ playerid ] ), refundEditingRefund[ playerid ] );
				}
			}else ShowPlayerRefundDialog( playerid, playerid );
		}
	}
	return ( true );
}
Hook:refund_OnPlayerDisconnect( playerid, reason ){
	refundLevel[ playerid ] = 1;
	refundMaterials[ playerid ] = 0;
	refundArmsDealerSkill[ playerid ] = 0;
	refundCarJackerSkill[ playerid ] = 0;
	refundDetectiveSkill[ playerid ] = 0;
	refundLawyerSkill[ playerid ] = 0;
	refundMechanicSkill[ playerid ] = 0;
	refundDrugDealerSkill[ playerid ] = 0;
	refundSexSkill[ playerid ] = 0;
	refundBoxingSkill[ playerid ] = 0;
	refundFishingSkill[ playerid ] = 0;
	refundPizzaSkill[ playerid ] = 0;
	refundBusSkill[ playerid ] = 0;
	refundCannabis[ playerid ] = 0;
	refundCocaine[ playerid ] = 0;
	refundMeth[ playerid ] = 0;
	refundXanax[ playerid ] = 0;
	refundPromethazine[ playerid ] = 0;
	refundCodeine[ playerid ] = 0;
	refundLean[ playerid ] = 0;
	refundPlayingHours[ playerid ] = 2;
	refundHealthUpgrade[ playerid ] = 0;
	refundArmorUpgrade[ playerid ] = 0;
	refundEditingRefund[ playerid ] = INVALID_PLAYER_ID;
	refundPlayerAllowed[ playerid ] = false;
	refundPlayerAwaitingRefund[ playerid ] = false;
	return ( true );
}