/* Automatically generated by refactor.pl.
 *
 *
 * CMDNAME: chanlevhistory
 * CMDLEVEL: QCMD_HELPER
 * CMDARGS: 2
 * CMDDESC: View user access changes on a channel.
 * CMDFUNC: csc_dochanlevhistory
 * CMDPROTO: int csc_dochanlevhistory(void *source, int cargc, char **cargv);
 * CMDHELP: Usage: chanlevhistory <channel> [<duration>]
 * CMDHELP: Shows you recent modifications to a channels user access entries.
 * CMDHELP: Default duration is one hour.
 */

#include "../chanserv.h"
#include "../../nick/nick.h"
#include "../../lib/flags.h"
#include "../../lib/irc_string.h"
#include "../../channel/channel.h"
#include "../../parser/parser.h"
#include "../../irc/irc.h"
#include "../../localuser/localuserchannel.h"
#include "../../pqsql/pqsql.h"

#include <libpq-fe.h>
#include <string.h>
#include <stdio.h>

void csdb_dochanlevhistory_real(PGconn *dbconn, void *arg) {
  nick *np=getnickbynumeric((unsigned long)arg);
  reguser *rup, *crup1, *crup2;
  unsigned int userID, channelID, targetID;
  time_t changetime, authtime;
  flag_t oldflags, newflags;
  PGresult *pgres;
  int i, num, count=0;
  struct tm *tmp;
  char tbuf[15], fbuf[18];

  if(!dbconn) {
    PQclear(pgres);
    return;
  }

  pgres=PQgetResult(dbconn);

  if (PQresultStatus(pgres) != PGRES_TUPLES_OK) {
    Error("chanserv", ERR_ERROR, "Error loading chanlev history data.");
    return;
  }

  if (PQnfields(pgres) != 7) {
    Error("chanserv", ERR_ERROR, "Chanlev history data format error.");
    PQclear(pgres);
    return;
  }
  num=PQntuples(pgres);

  if (!np) {
    PQclear(pgres);
    return;
  }

  if (!(rup=getreguserfromnick(np)) || !UHasHelperPriv(rup)) {
    PQclear(pgres);
    return;
  }

  chanservsendmessage(np, "Number: Time:           Changing user:  Changed user:   Old flags:      New flags:");
  for (i=0; i<num; i++) {
    userID=strtoul(PQgetvalue(pgres, i, 0), NULL, 10);
    channelID=strtoul(PQgetvalue(pgres, i, 1), NULL, 10);
    targetID=strtoul(PQgetvalue(pgres, i, 2), NULL, 10);
    changetime=strtoul(PQgetvalue(pgres, i, 3), NULL, 10);
    authtime=strtoul(PQgetvalue(pgres, i, 4), NULL, 10);
    oldflags=strtoul(PQgetvalue(pgres, i, 5), NULL, 10);
    newflags=strtoul(PQgetvalue(pgres, i, 6), NULL, 10);
    tmp=localtime(&changetime);
    strftime(tbuf, 15, "%d/%m/%y %H:%M", tmp);
    strncpy(fbuf, printflags(oldflags, rcuflags), 17);
    fbuf[17]='\0';
    chanservsendmessage(np, "#%-6d %-15s %-15s %-15s %-15s %s", ++count, tbuf,
      (crup1=findreguserbyID(userID))?crup1->username:"Unknown", (crup2=findreguserbyID(targetID))?crup2->username:"Unknown",
      fbuf, printflags(newflags, rcuflags));
  }
  chanservstdmessage(np, QM_ENDOFLIST);

  PQclear(pgres);
}

void csdb_retreivechanlevhistory(nick *np, regchan *rcp, time_t starttime) {
  q9c_asyncquery(csdb_dochanlevhistory_real, (void *)np->numeric,
    "SELECT userID, channelID, targetID, changetime, authtime, oldflags, newflags from chanlevhistory where "
    "channelID=%u and changetime>%lu order by changetime desc limit 1000", rcp->ID, starttime);
}

int csc_dochanlevhistory(void *source, int cargc, char **cargv) {
  nick *sender=source;
  chanindex *cip;
  regchan *rcp;
  unsigned long interval;

  if (cargc < 1) {
    chanservstdmessage(sender, QM_NOTENOUGHPARAMS, "chanlevhistory");
    return CMD_ERROR;
  }
  
  if (!(cip=cs_checkaccess(sender, cargv[0], 0, NULL, NULL, 0, 0)))
    return CMD_ERROR;
  
  rcp=(regchan*)cip->exts[chanservext];
  
  if (cargc > 1)
    interval=durationtolong(cargv[1]);
  else
    interval=3600;
 
  chanservstdmessage(sender, QM_SHOWINGDURATION, "chanlevhistory", longtoduration(interval,1));
  csdb_retreivechanlevhistory(sender, rcp, getnettime()-interval);
  
  return CMD_OK;
}
