#include "chanserv.h"
#include "../lib/irc_string.h"
#include "../core/schedule.h"

void chanservdgline(void* arg) {
  reguser *rup=(reguser*)arg;
  nick *np, *nl;
  authname *anp;
  int i;
  unsigned int ucount;
  
  if (!rup)
    return;
  
  if (!(anp=findauthname(rup->ID)))
    return;
    
  for (nl=anp->nicks;nl;nl=nl->nextbyauthname) {
    for (i=0, ucount=0; i<NICKHASHSIZE; i++)
      for (np=nicktable[i];np;np=np->next)
        if (!ircd_strcmp(np->ident, nl->ident) && np->ipnode==nl->ipnode)
          ucount++;
    
    if (ucount >= MAXGLINEUSERS) {
      chanservwallmessage("Delayed GLINE \"*!%s@%s\" (account %s) would hit %d users, aborting.", 
        nl->ident, IPtostr(nl->p_ipaddr), rup->username, ucount);
    } else {
      irc_send("%s GL * +*!%s@%s 3600 :%s\r\n", mynumeric->content, nl->ident, 
        IPtostr(nl->p_ipaddr), rup->suspendreason->content);
      chanservwallmessage("Delayed GLINE \"*!%s@%s\" (authed as %s) expires in 60 minute/s (hit %d user%s) (reason: %s)", 
        nl->ident, IPtostr(nl->p_ipaddr), rup->username, ucount, ucount==1?"":"s", rup->suspendreason->content);
    }
  }
}
