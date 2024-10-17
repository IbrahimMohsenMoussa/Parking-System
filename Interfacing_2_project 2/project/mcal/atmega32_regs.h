#ifndef ATMEGA32_REGISTERS_H
#define ATMEGA32_REGISTERS_H

#include<stdint.h>      /**< Unsigned 16-bit integer (0 to 65535). */
// GPIO Ports
union PORTA_reg {
    uint8_t byte;
    struct {
        uint8_t pa0 :1;
        uint8_t pa1 :1;
        uint8_t pa2 :1;
        uint8_t pa3 :1;
        uint8_t pa4 :1;
        uint8_t pa5 :1;
        uint8_t pa6 :1;
        uint8_t pa7 :1;
    } bits;
};
union DDRA_reg {
    uint8_t byte;
    struct {
        uint8_t dda0 :1;
        uint8_t dda1 :1;
        uint8_t dda2 :1;
        uint8_t dda3 :1;
        uint8_t dda4 :1;
        uint8_t dda5 :1;
        uint8_t dda6 :1;
        uint8_t dda7 :1;
    } bits;
};
union PINA_reg {
    uint8_t byte;
    struct {
        uint8_t pina0 :1;
        uint8_t pina1 :1;
        uint8_t pina2 :1;
        uint8_t pina3 :1;
        uint8_t pina4 :1;
        uint8_t pina5 :1;
        uint8_t pina6 :1;
        uint8_t pina7 :1;
    } bits;
};

union PORTB_reg {
    uint8_t byte;
    struct {
        uint8_t pb0 :1;
        uint8_t pb1 :1;
        uint8_t pb2 :1;
        uint8_t pb3 :1;
        uint8_t pb4 :1;
        uint8_t pb5 :1;
        uint8_t pb6 :1;
        uint8_t pb7 :1;
    } bits;
};
union DDRB_reg {
    uint8_t byte;
    struct {
        uint8_t ddb0 :1;
        uint8_t ddb1 :1;
        uint8_t ddb2 :1;
        uint8_t ddb3 :1;
        uint8_t ddb4 :1;
        uint8_t ddb5 :1;
        uint8_t ddb6 :1;
        uint8_t ddb7 :1;
    } bits;
};
union PINB_reg {
    uint8_t byte;
    struct {
        uint8_t pinb0 :1;
        uint8_t pinb1 :1;
        uint8_t pinb2 :1;
        uint8_t pinb3 :1;
        uint8_t pinb4 :1;
        uint8_t pinb5 :1;
        uint8_t pinb6 :1;
        uint8_t pinb7 :1;
    } bits;
};

union PORTC_reg {
    uint8_t byte;
    struct {
        uint8_t pc0 :1;
        uint8_t pc1 :1;
        uint8_t pc2 :1;
        uint8_t pc3 :1;
        uint8_t pc4 :1;
        uint8_t pc5 :1;
        uint8_t pc6 :1;
        uint8_t pc7 :1;
    } bits;
};
union DDRC_reg {
    uint8_t byte;
    struct {
        uint8_t ddc0 :1;
        uint8_t ddc1 :1;
        uint8_t ddc2 :1;
        uint8_t ddc3 :1;
        uint8_t ddc4 :1;
        uint8_t ddc5 :1;
        uint8_t ddc6 :1;
        uint8_t ddc7 :1;
    } bits;
};
union PINC_reg {
    uint8_t byte;
    struct {
        uint8_t pinc0 :1;
        uint8_t pinc1 :1;
        uint8_t pinc2 :1;
        uint8_t pinc3 :1;
        uint8_t pinc4 :1;
        uint8_t pinc5 :1;
        uint8_t pinc6 :1;
        uint8_t pinc7 :1;
    } bits;
};

union PORTD_reg {
    uint8_t byte;
    struct {
        uint8_t pd0 :1;
        uint8_t pd1 :1;
        uint8_t pd2 :1;
        uint8_t pd3 :1;
        uint8_t pd4 :1;
        uint8_t pd5 :1;
        uint8_t pd6 :1;
        uint8_t pd7 :1;
    } bits;
};
union DDRD_reg {
    uint8_t byte;
    struct {
        uint8_t ddd0 :1;
        uint8_t ddd1 :1;
        uint8_t ddd2 :1;
        uint8_t ddd3 :1;
        uint8_t ddd4 :1;
        uint8_t ddd5 :1;
        uint8_t ddd6 :1;
        uint8_t ddd7 :1;
    } bits;
};
union PIND_reg {
    uint8_t byte;
    struct {
        uint8_t pind0 :1;
        uint8_t pind1 :1;
        uint8_t pind2 :1;
        uint8_t pind3 :1;
        uint8_t pind4 :1;
        uint8_t pind5 :1;
        uint8_t pind6 :1;
        uint8_t pind7 :1;
    } bits;
};

// Timer/Counter 0
union TCCR0_reg {
    uint8_t byte;
    struct {
        uint8_t cs00 :1;
        uint8_t cs01 :1;
        uint8_t cs02 :1;
        uint8_t wgm01 :1;
        uint8_t com00 :1;
        uint8_t com01 :1;
        uint8_t wgm00 :1;
        uint8_t foc0 :1;
    } bits;
};

union TCNT0_reg {
    uint8_t byte;
};

union OCR0_reg {
    uint8_t byte;
};

// Timer/Counter 1
union TCCR1A_reg {
    uint8_t byte;
    struct {
        uint8_t wgm10 :1;
        uint8_t wgm11 :1;
        uint8_t foc1b :1;
        uint8_t foc1a :1;
        uint8_t com1b0 :1;
        uint8_t com1b1 :1;
        uint8_t com1a0 :1;
        uint8_t com1a1 :1;
    } bits;
};

union TCCR1B_reg {
    uint8_t byte;
    struct {
        uint8_t cs10 :1;
        uint8_t cs11 :1;
        uint8_t cs12 :1;
        uint8_t wgm12 :1;
        uint8_t wgm13 :1;
        uint8_t ices1 :1;
        uint8_t icnc1 :1;
        uint8_t :1;
    } bits;
};

union TCNT1_reg {
    struct {
        uint8_t tcnt1l;
        uint8_t tcnt1h;
    } bytes;
    uint16_t word;
};

union OCR1A_reg {
    struct {
        uint8_t ocr1al;
        uint8_t ocr1ah;
    } bytes;
    uint16_t word;
};

union OCR1B_reg {
    struct {
        uint8_t ocr1bl;
        uint8_t ocr1bh;
    } bytes;
    uint16_t word;
};

union ICR1_reg {
    struct {
        uint8_t icr1l;
        uint8_t icr1h;
    } bytes;
    uint16_t word;
};

// Timer/Counter 2
union TCCR2_reg {
    uint8_t byte;
    struct {
        uint8_t cs20 :1;
        uint8_t cs21 :1;
        uint8_t cs22 :1;
        uint8_t wgm21 :1;
        uint8_t com20 :1;
        uint8_t com21 :1;
        uint8_t wgm20 :1;
        uint8_t foc2 :1;
    } bits;
};

union TCNT2_reg {
    uint8_t byte;
};

union OCR2_reg {
    uint8_t byte;
};

// Interrupt Registers
union SREG_reg {
    uint8_t byte;
    struct {
        uint8_t c :1;
        uint8_t z :1;
        uint8_t n :1;
        uint8_t v :1;
        uint8_t s :1;
        uint8_t h :1;
        uint8_t t :1;
        uint8_t i :1;
    } bits;
};

union TIMSK_reg {
    uint8_t byte;
    struct {
        uint8_t toie0 :1;
        uint8_t ocie0 :1;
        uint8_t toie1 :1;
        uint8_t ocie1b :1;
        uint8_t ocie1a :1;
        uint8_t ticie1 :1;
        uint8_t toie2 :1;
        uint8_t ocie2 :1;
    } bits;
};

union TIFR_reg {
    uint8_t byte;
    struct {
        uint8_t tov0 :1;
        uint8_t ocf0 :1;
        uint8_t tov1 :1;
        uint8_t ocf1b :1;
        uint8_t ocf1a :1;
        uint8_t icf1 :1;
        uint8_t tov2 :1;
        uint8_t ocf2 :1;
    } bits;
};

// ADC Registers
union ADMUX_reg {
    uint8_t byte;
    struct {
        uint8_t mux0 :1;
        uint8_t mux1 :1;
        uint8_t mux2 :1;
        uint8_t mux3 :1;
        uint8_t mux4 :1;
        uint8_t adlar :1;
        uint8_t refs0 :1;
        uint8_t refs1 :1;
    } bits;
};

union ADCSRA_reg {
    uint8_t byte;
    struct {
        uint8_t adps0 :1;
        uint8_t adps1 :1;
        uint8_t adps2 :1;
        uint8_t adie :1;
        uint8_t adif :1;
        uint8_t adate :1;
        uint8_t adsc :1;
        uint8_t aden :1;
    } bits;
};

union ADC_reg {

    uint16_t value;
};

// EEPROM Registers
union EEAR_reg {
    struct {
        uint8_t eearl;
        uint8_t eearh;
    } bytes;
    uint16_t word;
};

union EEDR_reg {
    uint8_t byte;
};

union EECR_reg {
    uint8_t byte;
    struct {
        uint8_t eere :1;
        uint8_t eewe :1;
        uint8_t eemwe :1;
        uint8_t eerie :1;
        uint8_t :4;
    } bits;
};

// SPI Registers
union SPCR_reg {
    uint8_t byte;
    struct {
        uint8_t spr0 :1;
        uint8_t spr1 :1;
        uint8_t cpha :1;
        uint8_t cpol :1;
        uint8_t mstr :1;
        uint8_t dord :1;
        uint8_t spe :1;
        uint8_t spie :1;
    } bits;
};

union SPSR_reg {
    uint8_t byte;
    struct {
        uint8_t spi2x :1;
        uint8_t :5;
        uint8_t wcol :1;
        uint8_t spif :1;
    } bits;
};

union SPDR_reg {
    uint8_t byte;
};

// USART Registers
union UBRRH_reg {
    uint8_t byte;
    struct {
        uint8_t ubrr8 :1;
        uint8_t ubrr9 :1;
        uint8_t ubrr10 :1;
        uint8_t ubrr11 :1;
        uint8_t :3;
        uint8_t ursel :1;
    } bits;
};

union UBRRL_reg {
    uint8_t byte;
};

union UCSRA_reg {
    uint8_t byte;
    struct {
        uint8_t mpcm :1;
        uint8_t u2x :1;
        uint8_t pe :1;
        uint8_t dor :1;
        uint8_t fe :1;
        uint8_t udre :1;
        uint8_t txc :1;
        uint8_t rxc :1;
    } bits;
};

union UCSRB_reg {
    uint8_t byte;
    struct {
        uint8_t txb8 :1;
        uint8_t rxb8 :1;
        uint8_t ucsz2 :1;
        uint8_t txen :1;
        uint8_t rxen :1;
        uint8_t udrie :1;
        uint8_t txcie :1;
        uint8_t rxcie :1;
    } bits;
};

union UCSRC_reg {
    uint8_t byte;
    struct {
        uint8_t ucpol :1;
        uint8_t ucsz0 :1;
        uint8_t ucsz1 :1;
        uint8_t usbs :1;
        uint8_t upm0 :1;
        uint8_t upm1 :1;
        uint8_t umsel :1;
        uint8_t ursel :1;
    } bits;
};

union UDR_reg {
    uint8_t byte;
};

// TWI Registers
union TWBR_reg {
    uint8_t byte;
};

union TWSR_reg {
    uint8_t byte;
    struct {
        uint8_t twps0 :1;
        uint8_t twps1 :1;
        uint8_t :1;
        uint8_t tws3 :1;
        uint8_t tws4 :1;
        uint8_t tws5 :1;
        uint8_t tws6 :1;
        uint8_t tws7 :1;
    } bits;
};

union TWAR_reg {
    uint8_t byte;
    struct {
        uint8_t twgce :1;
        uint8_t twa0 :1;
        uint8_t twa1 :1;
        uint8_t twa2 :1;
        uint8_t twa3 :1;
        uint8_t twa4 :1;
        uint8_t twa5 :1;
        uint8_t twa6 :1;
    } bits;
};

union TWDR_reg {
    uint8_t byte;
};

union TWCR_reg {
    uint8_t byte;
    struct {
        uint8_t twie :1;
        uint8_t twen :1;
        uint8_t twwc :1;
        uint8_t twsto :1;
        uint8_t twsta :1;
        uint8_t twea :1;
        uint8_t twint :1;
        uint8_t :1;
    } bits;
};

// Watchdog Timer
union WDTCR_reg {
    uint8_t byte;
    struct {
        uint8_t wdp0 :1;
        uint8_t wdp1 :1;
        uint8_t wdp2 :1;
        uint8_t wde :1;
        uint8_t wdtoe :1;
        uint8_t :3;
    } bits;
};

// Power Management, Oscillators, and Miscellaneous
union OSCCAL_reg {
    uint8_t byte;
};

union SFIOR_reg {
    uint8_t byte;
    struct {
        uint8_t psr10 :1;
        uint8_t psr2 :1;
        uint8_t pud :1;
        uint8_t acme :1;
        uint8_t adts0 :1;
        uint8_t adts1 :1;
        uint8_t adts2 :1;
        uint8_t :1;
    } bits;
};

union MCUCSR_reg {
    uint8_t byte;
    struct {
        uint8_t porf :1;
        uint8_t extrf :1;
        uint8_t borf :1;
        uint8_t wdrf :1;
        uint8_t jtrf :1;
        uint8_t :3;
    } bits;
};

union MCUCR_reg {
    uint8_t byte;
    struct {
        uint8_t isc00 :1;
        uint8_t isc01 :1;
        uint8_t isc10 :1;
        uint8_t isc11 :1;
        uint8_t sm0 :1;
        uint8_t sm1 :1;
        uint8_t sm2 :1;
        uint8_t se :1;
    } bits;
};

union SPMCR_reg {
    uint8_t byte;
    struct {
        uint8_t spmen :1;
        uint8_t pgers :1;
        uint8_t pgwrt :1;
        uint8_t blbset :1;
        uint8_t rwwsre :1;
        uint8_t rwwsb :1;
        uint8_t spmie :1;
        uint8_t :1;
    } bits;
};

// Memory-mapped register macros
#define PORTA_REG   (*((volatile union PORTA_reg *)0x3B))
#define DDRA_REG    (*((volatile union DDRA_reg *)0x3A))
#define PINA_REG    (*((volatile union PINA_reg *)0x39))

#define PORTB_REG   (*((volatile union PORTB_reg *)0x38))
#define DDRB_REG    (*((volatile union DDRB_reg *)0x37))
#define PINB_REG    (*((volatile union PINB_reg *)0x36))

#define PORTC_REG   (*((volatile union PORTC_reg *)0x35))
#define DDRC_REG    (*((volatile union DDRC_reg *)0x34))
#define PINC_REG    (*((volatile union PINC_reg *)0x33))

#define PORTD_REG   (*((volatile union PORTD_reg *)0x32))
#define DDRD_REG    (*((volatile union DDRD_reg *)0x31))
#define PIND_REG    (*((volatile union PIND_reg *)0x30))

// Timer/Counter 0

#define TCCR0_REG   (*((volatile union TCCR0_reg *)0x53))
#define TCNT0_REG   (*((volatile union TCNT0_reg *)0x52))
#define OCR0_REG    (*((volatile union OCR0_reg *)0x5C))
// Timer/Counter 1
#define TCCR1A_REG  (*((volatile union TCCR1A_reg *)0x4F))
#define TCCR1B_REG  (*((volatile union TCCR1B_reg *)0x4E))
#define TCNT1_REG   (*((volatile union TCNT1_reg *)0x4C))
#define OCR1A_REG   (*((volatile union OCR1A_reg *)0x4A))
#define OCR1B_REG   (*((volatile union OCR1B_reg *)0x48))
#define ICR1_REG    (*((volatile union ICR1_reg *)0x46))

// Timer/Counter 2
#define TCCR2_REG   (*((volatile union TCCR2_reg *)0x45))
#define TCNT2_REG   (*((volatile union TCNT2_reg *)0x44))
#define OCR2_REG    (*((volatile union OCR2_reg *)0x43))

// Interrupt Registers
#define SREG_REG    (*((volatile union SREG_reg *)0x5F))
#define TIMSK_REG   (*((volatile union TIMSK_reg *)0x59))
#define TIFR_REG    (*((volatile union TIFR_reg *)0x58))

// ADC Registers
#define ADMUX_REG   (*((volatile union ADMUX_reg *)0x27))
#define ADCSRA_REG  (*((volatile union ADCSRA_reg *)0x26))
#define ADC_REG     (*((volatile union ADC_reg *)0x24))

// EEPROM Registers
#define EEAR_REG    (*((volatile union EEAR_reg *)0x3E))
#define EEDR_REG    (*((volatile union EEDR_reg *)0x3D))
#define EECR_REG    (*((volatile union EECR_reg *)0x3C))

// SPI Registers
#define SPCR_REG    (*((volatile union SPCR_reg *)0x2D))
#define SPSR_REG    (*((volatile union SPSR_reg *)0x2E))
#define SPDR_REG    (*((volatile union SPDR_reg *)0x2F))

// USART Registers
#define UBRRH_REG   (*((volatile union UBRRH_reg *)0x40))
#define UBRRL_REG   (*((volatile union UBRRL_reg *)0x29))
#define UCSRA_REG   (*((volatile union UCSRA_reg *)0x2B))
#define UCSRB_REG   (*((volatile union UCSRB_reg *)0x2A))
#define UCSRC_REG   (*((volatile union UCSRC_reg *)0x40))
#define UDR_REG     (*((volatile union UDR_reg *)0x2C))

// TWI Registers
#define TWBR_REG    (*((volatile union TWBR_reg *)0x20))
#define TWSR_REG    (*((volatile union TWSR_reg *)0x21))
#define TWAR_REG    (*((volatile union TWAR_reg *)0x22))
#define TWDR_REG    (*((volatile union TWDR_reg *)0x23))
#define TWCR_REG    (*((volatile union TWCR_reg *)0x56))

// Watchdog Timer
#define WDTCR_REG   (*((volatile union WDTCR_reg *)0x41))

// Oscillator and Power Management
#define OSCCAL_REG  (*((volatile union OSCCAL_reg *)0x51))
#define SFIOR_REG   (*((volatile union SFIOR_reg *)0x50))
#define MCUCSR_REG  (*((volatile union MCUCSR_reg *)0x54))
#define MCUCR_REG   (*((volatile union MCUCR_reg *)0x55))
#define SPMCR_REG   (*((volatile union SPMCR_reg *)0x57))

#endif // ATMEGA32_REGISTERS_H
