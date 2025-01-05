#include <stdint.h>
#include "tests/tests.h"


// Define the test by set the name of the define as TEST_*PERIPHERAL*_*TESTCASE*
// EX: TEST_GPIO_TOOGLE_PIN

// NOTE: All the tests case run into a single thread in an infinite loop, so we can just try one at once
// so this is more like an example select then a test routine but i don't care
#define TEST_USART_TRASMITTER_BUFFER // SET TEST CASE

int main(void)
{

#ifdef TEST_GPIO_TOOGLE_PIN
	GPIO_TEST_TOOGLE_PIN();
#endif

#ifdef TEST_USART_TRASMITTER_BYTE
	USART_TEST_TRANSMITTE_SINGLE_BYTE();
#endif

#ifdef TEST_USART_TRASMITTER_BUFFER
	USART_TEST_TRANSMITTE_BUFFER();

#endif

#ifdef TEST_USART_RECEIVER

#endif

}
