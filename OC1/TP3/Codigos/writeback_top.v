`ifndef WRITEBACK_V
  `define WRITEBACK_V

  `include "utils.vh"

  module writeback_top1 (
		output wire [6:0] disp1, disp2,
      output wire [3:0] r_out,
      input wire  [2:0] reg_addr1, reg_addr2, reg_addr3,
      input wire  [3:0] data,
      input wire  [2:0] oper, 
      input wire sel, write_en, clk
    );

    wire [`CPU_WSIZE-1:0] write_data, read_data1, read_data2, wresult;
    wire [`RSEL_WIDTH-1:0] wread_addr1, wread_addr2, wread_addr3;
    wire [`ALU_OSIZE:0] wop;

	 //reg [`CPU_WSIZE-1:0] led_red, led_green;
	 
    registers#(`CPU_WSIZE, `RSEL_WIDTH) registers_wb(.read_data1(read_data1),     .read_data2(read_data2), 
                                                     .write_data(write_data),     .read_address1(wread_addr1), 
                                                     .read_address2(wread_addr2), .write_address(wread_addr3), 
                                                     .write_en(write_en),         .clk(clk));
	//assign led_red = read_data1;
	//assign led_green = read_data2;
	hex_7seg hex_7seg1(read_data1, disp1);
	hex_7seg hex_7seg2(read_data2, disp2);

    alu alu_wb(.r(wresult), .zero(zero), .ovf(ovf), .op(wop), .a(read_data1), .b(read_data2));
 
    assign wread_addr1 = reg_addr1;
    assign wread_addr2 = reg_addr2;
    assign wread_addr3 = reg_addr3;
    assign r_out = wresult;
    assign wop = oper;
    
    assign write_data = sel == 0 ? data : wresult;

  endmodule

    module writeback_top (
		input wire CLOCK_50,
		input wire [17:0] SW,
		input wire [3:0]KEY,
		output [6:0] HEX0,
      output [6:0] HEX1,
      output [6:0] HEX2
	);

	 wire [3:0]r_disp;
	 
	 writeback_top1 writeback0(HEX2, HEX1, r_disp, SW[2:0], SW[5:3], SW[8:6], SW[12:9], SW[16:15], SW[17], !KEY[2], CLOCK_50);
	 hex_7seg hex_7seg0(r_disp, HEX0);
	endmodule
	
`endif // WRITEBACK_V

