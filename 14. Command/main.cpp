#include "Command.h"

int main(void)
{
	BandAccount bank;
	//BandAccountCommand cmd{ bank, BandAccountCommand::Action::deposit, 500 };
	
	BandAccount bankA;
	BandAccount bankB;
	MoneyTransferCommand cmd( bankA, bankB, 300 );
	cmd.call();

}