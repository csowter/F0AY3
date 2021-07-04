namespace
{
	unsigned int r0;
	unsigned int r1;
	unsigned int r2;
	unsigned int r3;
	unsigned int r12;
	unsigned int lr;
	unsigned int pc;
	unsigned int xPSR;
}
extern "C" void HardfaultHandler(unsigned int *sp)
{
	r0 = *sp++;
	r1 = *sp++;
	r2 = *sp++;
	r3 = *sp++;
	r12 = *sp++;
	lr = *sp++;
	pc = *sp++;
	xPSR = *sp++;
	
	while(1);
}
