#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" //For C types
{
#include "mock_antenna_interface.h"
#include "mock_obdh.h"
#include "mock_sleep.h"
#include "mock_ttc_interface.h"
}

#include "ttc_interface.h" 


TEST_GROUP (TTCPollingThreadTestGroup)
{
    //Define variables
    int result;

    void setup()
    {
        //Setup variables
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

/*
1 - Implementar erros das funções do driver e da interface caso return -1
2 - Testar criação de pacotes do NGHam e decodificação mantém os dados
3-  Recebimento de confirmação de recebimento e envio da GRS
4 - Implementar contador de envio de pacotes e tbm de quando forem bem enviados
5 - implemntar delay entre instruçoes, mais seguro
*/