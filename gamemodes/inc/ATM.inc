#define MAX_ATMS ( 500 )

#define INVALID_ATM_ID ( -1 )

new Iterator: Atms< MAX_ATMS >;

new ATMID[ MAX_ATMS ];

new EditingAtm[ MAX_PLAYERS ];

enum ATM 
{
	Float: atm_X,
	Float: atm_Y,
	Float: atm_Z,
	Float: atm_fX,
	Float: atm_fY,
	Float: atm_fZ,
	AtmObject,
	bool:Save
}

new AtmInfo[ MAX_ATMS ] [ ATM ];

forward LoadATMS();
public LoadATMS()
{
	new rows = cache_num_rows( );
 	if( rows )
  	{
   		new atmid, loaded;
		while( loaded < rows )
		{
  			atmid = cache_get_field_content_int( loaded, "ID" );
		    AtmInfo [ atmid ] [ atm_X ] = cache_get_field_content_float( loaded, "atm_X" );
		    AtmInfo [ atmid ] [ atm_Y ] = cache_get_field_content_float( loaded, "atm_Y" );
		    AtmInfo [ atmid ] [ atm_Z ] = cache_get_field_content_float( loaded, "atm_Z" );
		    AtmInfo [ atmid ] [ atm_fX ] = cache_get_field_content_float( loaded, "atm_fX" );
		    AtmInfo [ atmid ] [ atm_fY ] = cache_get_field_content_float( loaded, "atm_fY" );
		    AtmInfo [ atmid ] [ atm_fZ ] = cache_get_field_content_float( loaded, "atm_fZ" );
		    AtmInfo[ atmid ] [ AtmObject ] = CreateObject( 19324, AtmInfo [ atmid ] [ atm_X ], AtmInfo [ atmid ] [ atm_Y ], AtmInfo [ atmid ] [ atm_Z ],  AtmInfo [ atmid ] [ atm_fX ], AtmInfo [ atmid ] [ atm_fY ], AtmInfo [ atmid ] [ atm_fZ ], 50 );
   			AtmInfo[ atmid ] [ Save ] = true;
   			Iter_Add( Atms, atmid );
   			ATMID [ atmid ] = atmid;
		    loaded ++;
	    }
	    printf( "Loaded %d ATMs.", loaded );
	}	
	return 1;
}

/*Hook:a_OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{
	new Float:oldX, Float:oldY, Float:oldZ, Float:oldRotX, Float:oldRotY, Float:oldRotZ, str[150];
	GetObjectPos(objectid, oldX, oldY, oldZ);
	GetObjectRot(objectid, oldRotX, oldRotY, oldRotZ);

	if(response == EDIT_RESPONSE_FINAL && EditingAtm[ playerid ])
	{
		new query[500];
		DestroyObject(AtmInfo[ EditingAtm[ playerid ] ] [ AtmObject ]);
		AtmInfo[EditingAtm[ playerid ] ] [atm_X] = fX;
		AtmInfo[EditingAtm[ playerid ] ] [atm_Y] = fY;
		AtmInfo[EditingAtm[ playerid ] ] [atm_Z] = fZ;
		AtmInfo[EditingAtm[ playerid ] ] [atm_fX] = fRotX;
		AtmInfo[EditingAtm[ playerid ] ] [atm_fY] = fRotY;
		AtmInfo[EditingAtm[ playerid ] ] [atm_fZ] = fRotZ;
		AtmInfo[ EditingAtm[ playerid ] ] [ AtmObject ] = CreateObject( 19324, AtmInfo [ EditingAtm[ playerid ] ] [ atm_X ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_Y ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_Z ],  
			AtmInfo [ EditingAtm[ playerid ] ] [ atm_fX ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_fY ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_fZ ], 50 );
		mysql_format( sqlGameConnection, query, sizeof( query ), "UPDATE `atm` SET `atm_X`='%f', `atm_Y`='%f', `atm_Z`='%f', `atm_fX`='%f', `atm_fY`='%f', `atm_fZ`='%f' WHERE `ID`='%d'", AtmInfo [ EditingAtm[ playerid ] ] [ atm_X ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_Y ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_Z ],  
			AtmInfo [ EditingAtm[ playerid ] ] [ atm_fX ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_fY ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_fZ ], EditingAtm[ playerid ] );
		mysql_tquery( sqlGameConnection, query, "", "" );
		format( str, sizeof( str ), "You've adjusted position of ATM ID: %d", EditingAtm[ playerid ]);
		SendClientMessage(playerid, -1, str);
	}
	if(response == EDIT_RESPONSE_CANCEL && EditingAtm[ playerid ])
	{
		DestroyObject( AtmInfo[ EditingAtm[ playerid ] ] [ AtmObject ] );
		AtmInfo[ EditingAtm[ playerid ] ] [ AtmObject ] = CreateObject( 19324, AtmInfo [ EditingAtm[ playerid ] ] [ atm_X ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_Y ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_Z ],  
			AtmInfo [ EditingAtm[ playerid ] ] [ atm_fX ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_fY ], AtmInfo [ EditingAtm[ playerid ] ] [ atm_fZ ], 50 );
		format( str, sizeof( str ), "You haven't adjusted the position of ATM ID: %d as you canceled it", EditingAtm[ playerid ]);
		SendClientMessage(playerid, -1, str);
	}
	return 1;
}*/

CMD:createatm( playerid, params[] )
{
	new atmid = Iter_Free( Atms ), Float: x, Float: y, Float: z, query[500], str[100];
	if( PlayerInfo[ playerid ] [ pAdmin ] < 3 ) SendClientMessage( playerid, -1, "Not authorized!" );
	else if( atmid == -1 ) SendClientMessage(playerid, -1, "MAX ATMS has reached");
	else
	{
		GetPlayerPos( playerid, x, y, z );
		AtmInfo[ atmid ] [ AtmObject ] = CreateObject( 19324, x, y, z, 0, 0, 0, 50 );
		SetPlayerPos(playerid, x+2, y+2, z+2);
		AtmInfo[ atmid ] [ Save ] = true;
		AtmInfo[ atmid ] [ atm_X ] = x;
		AtmInfo[ atmid ] [ atm_Y ] = y;
		AtmInfo[ atmid ] [ atm_Z ] = z;
		mysql_format( sqlGameConnection, query, sizeof( query ), "INSERT INTO `atm` SET `ID`='%d', `atm_X`='%f', `atm_Y`='%f', `atm_Z`='%f'", atmid, x, y, z );
		mysql_tquery( sqlGameConnection, query, "", "" );
		Iter_Add(Atms, atmid);
		ATMID [ atmid ] = atmid;
		format(str, sizeof(str), "{00BFFF}You've successfully created an ATM - {FFFFFF}ID: %d", atmid);
		SendClientMessage(playerid, -1, str);
	}
	return 1;
}

CMD:gotoatm( playerid, params[] )
{
	new atmid, str[100];
	if( PlayerInfo[ playerid ] [ pAdmin ] < 3 ) SendClientMessage( playerid, -1, "Not authorized!" );
	else if( sscanf( params, "i", atmid ) ) SendClientMessage( playerid, -1, "{00BFFF}Usage:{FFFFFF} /gotoatm [id]" );
	else if( !Iter_Contains( Atms, atmid ) ) SendClientMessage( playerid, -1, "{FF0000}Error:{FFFFFF} The ATM ID you entered does not exist!" );
	else
	{
		SetPlayerPos(playerid, AtmInfo [ atmid ] [ atm_X ]+2, AtmInfo [ atmid ] [ atm_Y ]+2, AtmInfo [ atmid ] [ atm_Z ]+2);
		format( str, sizeof( str ), "{00BFFF}You've successfully teleported to ATM - {FFFFFF}ID: %d", atmid );
		SendClientMessage( playerid, -1, str );
	}
	return 1;
}

CMD:deleteatm( playerid, params[] )
{
	new atmid, query[100], str[100];
	if( PlayerInfo[ playerid ] [ pAdmin ] < 3 ) SendClientMessage( playerid, -1, "Not authorized!" );
	else if( sscanf( params, "i", atmid ) ) SendClientMessage( playerid, -1, "{00BFFF}Usage: {FFFFFF}/deleteatm [id]" );
	else if( !Iter_Contains( Atms, atmid ) ) SendClientMessage( playerid, -1, "{FF0000}Error:{FFFFFF} The ATM ID you entered does not exist!" );
	else
	{
		DestroyObject( AtmInfo[ atmid ] [ AtmObject ] );
		AtmInfo [ atmid ] [ atm_X ] = 0;
		AtmInfo [ atmid ] [ atm_Y ] = 0;
		AtmInfo [ atmid ] [ atm_Z ] = 0;
		Iter_Remove( Atms, atmid );
		mysql_format( sqlGameConnection, query, sizeof( query ), "DELETE FROM `atm` WHERE `ID`='%d'", atmid);
		mysql_tquery( sqlGameConnection, query, "", "" );
		format( str, sizeof( str ), "{00BFFF}You've successfully deleted ATM - {FFFFFF}ID: %d", atmid );
		SendClientMessage( playerid, -1, str );
	}
	return 1;
}

CMD:getatmid( playerid )
{
    new str[ 32 ];
    if( PlayerInfo[ playerid ] [ pAdmin ] < 3 ) return SendClientMessage( playerid, -1, "Not authorized!" );
    for( new i; i < MAX_ATMS; i++ )
    {
        if(IsPlayerInRangeOfPoint( playerid, 2.0, AtmInfo[ i ] [ atm_X ], AtmInfo[ i ] [ atm_Y ], AtmInfo[ i ] [ atm_Z ] ) )
        {
            format( str, sizeof str, "ATM ID is %d", ATMID[ i ] ); 
            SendClientMessage( playerid, -1, str );
            return 1;
        }
    }
    SendClientMessage( playerid, -1, "You're not near any ATM!" );
    return 1;
}

CMD:editatm( playerid, params[] )
{
	new atmid, str[125];
	if( PlayerInfo[ playerid ] [ pAdmin ] < 3 ) SendClientMessage( playerid, -1, "Not authorized!" );
	else if( sscanf( params, "i", atmid ) ) SendClientMessage( playerid, -1, "{00BFFF}Usage: {FFFFFF}/editatm [id]" );
	else if( !Iter_Contains( Atms, atmid ) ) SendClientMessage( playerid, -1, "{FF0000}Error:{FFFFFF} The ATM ID you entered does not exist!" );
	else
	{
		EditObject(playerid, AtmInfo[ atmid ] [ AtmObject] );
		format( str, sizeof( str ), "You're editing ATM ID: %d", atmid );
		SendClientMessage( playerid, -1, str );
		EditingAtm[ playerid ] = atmid;
	}
	return 1;
}
