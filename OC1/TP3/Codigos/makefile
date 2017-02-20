TARGET   = writeback
SOURCE   = writeback_top.v alu.v registers.v writeback_tb.v
IVERILOG = iverilog
VVP      = vvp
WAVE     = gtkwave

all: $(TARGET).vcd

$(TARGET).vvp : $(SOURCE)
	$(IVERILOG) -gstrict-expr-width -o $(TARGET).vvp $(SOURCE)
#
$(TARGET).vcd : $(TARGET).vvp
	$(VVP) $(TARGET).vvp
#
view : all
	$(WAVE) $(TARGET).vcd
#
clean :
	rm *.vvp *.vcd
