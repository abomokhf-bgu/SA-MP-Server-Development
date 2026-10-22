#include <YSI\y_hooks>

new restartsv;
new restarttimer;
new pkicktimer[MAX_PLAYERS];

CMD:restart(playerid, params[])
{
	if(PlayerInfo[playerid][pAdmin] < 1337) return AdmErrorMsg;
	new reason[1000], seconds, string[1000];
	if (sscanf(params, "ds", seconds, reason)) return SendClientMessage(playerid, COLOR_WHITE, "Usage: /restart [seconds] [reason]");
 	format(string, sizeof(string), "~ Server restart in %d seconds reason: %s", seconds, reason);
	SendClientMessageToAll(COLOR_DARKRED, string);
	SaveChars();
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Player/Server data has been saved.");
	restartsv = seconds;
	restarttimer = SetTimer("Restarting", 1000, 1);
	return 1;
}
forward Restarting();
public Restarting()
{
     restartsv--; 
     new str[1000];
     if(restartsv == 0)
     {
		foreach(new i: Player)
		{
		
			KillTimer(restarttimer);
            SQLSave(i);
			Kick(i);
			SendRconCommand("gmx");

		}
     }
     else
     {
        format(str, sizeof(str), "~w~Server Restarting in ~r~%d ~w~seconds.", restartsv);
        GameTextForAll(str, 1000, 3);
     }
     return 1;
}
forward KickBanTimer(playerid, kickban);
public KickBanTimer(playerid, kickban)
{
	switch (kickban)
	{
		case 1: Kick(playerid);
		case 2: Ban(playerid);
	}
	KillTimer(pkicktimer[playerid]);
	pkicktimer[playerid] = 0;
}
