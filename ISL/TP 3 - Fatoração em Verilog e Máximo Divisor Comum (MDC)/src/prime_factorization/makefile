TARGET   = fatorador
#SOURCE   = pfact_top.v pfact_engine.v bin_to_bcd.v hex_to_7seg.v
SOURCE   = fatorador_top.v fatorador_engine.v hex_to_7seg.v bin_to_bcd.v testador.v
IVERILOG = iverilog
VVP      = vvp
WAVE     = gtkwave

all: $(TARGET).vcd

$(TARGET).vvp : $(SOURCE)
	$(IVERILOG) -o $(TARGET).vvp $(SOURCE)
#
$(TARGET).vcd : $(TARGET).vvp
	$(VVP) $(TARGET).vvp
#
view : all
	$(WAVE) $(TARGET).vcd
#
clean :
	rm *.vvp *.vcd
