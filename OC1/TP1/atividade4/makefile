TARGET   = alu
#SOURCE   = alu_top.v alu.v
SOURCE   = alu.v alu_tb.v
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
