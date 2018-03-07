#include "delegate.h"

/*  ================================================  */
/*  =====  */
/*  Description  */
void ARK::Delegate::Delegate::description(char* const buf, size_t /*size*/) const
{
    //TODO:  check len for sufficient size  
    strcpy(buf, "username: ");
    strcat(buf, this->username_);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address_.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey_.description());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote_.ark());
    strcat(buf, "\nproducedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->producedblocks_);
    strcat(buf, "\nmissedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->missedblocks_);
    strcat(buf, "\nrate: ");
    sprintf(buf + strlen(buf), "%d", this->rate_);
    strcat(buf, "\napproval: ");
    sprintf(buf + strlen(buf), "%f", this->approval_);
    strcat(buf, "%\nproductivity: ");
    sprintf(buf + strlen(buf), "%f", this->productivity_);
    strcat(buf, "%");
}
/*  =====  */
/*  ================================================  */
