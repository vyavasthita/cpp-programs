#include <tccore/custom.h>
#include <user_exits/user_exits.h>
#include <server_exits/user_server_exits.h>
#include <epm.h>


EPM_decision_t ABi_Rule_Handler(EPM_rule_message_t msg)
{
	EPM_decision_t decision = EPM_nogo;

	return decision;
}


int ABi_Action_Handler(EPM_action_message_t msg)
{
	printf("ABi_Action_Handler  is called.");
	return ( ITK_ok );
}


extern DLLAPI int my_custom_exit_function(int *decision, va_list args)
{
int rcode = ITK_ok;
fprintf(stdout, "Acknowledged that custom exit has been run!\n");
*decision = ALL_CUSTOMIZATIONS;
rcode = EPM_register_action_handler("ABi_Action_Handler", "",ABi_Action_Handler);

if (rcode == ITK_ok)
fprintf(stdout, "Handler ABi_Action_Handler successfully registered!\n");
else
fprintf(stdout, "WARNING - Handler ABi_Action_Handler NOT registered!\n");


rcode = EPM_register_rule_handler("ABi_Rule_Handler", "",ABi_Rule_Handler);

if (rcode == ITK_ok)
fprintf(stdout, "Handler ABi_Rule_Handler successfully registered!\n");
else
fprintf(stdout, "WARNING - Handler ABi_Rule_Handler NOT registered!\n");
return rcode;

}


extern DLLAPI int tc_itk_cust_register_callbacks()
{
	
CUSTOM_register_exit( "tc_itk_cust", "USER_gs_shell_init_module",(CUSTOM_EXIT_ftn_t)my_custom_exit_function);

return ( ITK_ok );
}
