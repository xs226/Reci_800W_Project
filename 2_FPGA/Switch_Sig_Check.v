module Switch_Sig_Check(
	input		rstn_i,
	input		clk_in,  

	input		sw_in,
	output   sw_state

);

parameter 
	COUNT_NUM	= 8'd10,
	THD_NUM		= 8'd7;
reg[19:0] count;
reg[19:0] count_l;
reg cmd_req_flag;
reg sw_in_reg,sw_in_regr;

always @(posedge clk_in or negedge rstn_i)
	if(~rstn_i)
		begin
		sw_in_reg <= 1'b1;
		sw_in_regr <= 1'b1;
		end
	else
		begin
		sw_in_reg <= sw_in;
		sw_in_regr<= sw_in_reg;
		end
		
always @(posedge clk_in or negedge rstn_i)
	begin
	if(~rstn_i)
		begin
		count <= 8'd0;
		count_l <= 8'd0;
		cmd_req_flag <= 1'b0;
		end
	else if(count >= COUNT_NUM)
		begin
		count <= 8'd0;
		count_l <= 8'd0;
		if(count_l >= THD_NUM)
			cmd_req_flag <= 1'b1;
		else
			cmd_req_flag <= 1'b0;
		end
	else
		begin
		count <= count + 1'b1;
		if(~sw_in_regr)
			count_l <= count_l + 1'b1;
		else
			count_l <= count_l;
		end
	end

assign sw_state=cmd_req_flag;

endmodule