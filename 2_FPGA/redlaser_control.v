module Red_Laser_Control(
	input		rstn_i,
	input		clk_in,  

	input		sw_in,
	output   sw_state

);

parameter
  REDLGT_REQ_TIM = 26'd9600000,  //300ms
  REDLGT_REQOFF_THD = 16'd4800;  //300ms * 0.0005
  
reg redlgt_req_flag;
reg[25:0] redlgt_tcount_reg;
reg[15:0] redlgt_offcount_reg;
always @(posedge clk_in or negedge rstn_i)
  begin
  if(~rstn_i)
    begin
    redlgt_req_flag <= 1'b0;
    redlgt_tcount_reg <= 26'd0;
    redlgt_offcount_reg <= 16'd0;
    end
  else if(redlgt_tcount_reg >= REDLGT_REQ_TIM)
    begin
    redlgt_req_flag <= 1'b1;      //on redlgt request
    redlgt_tcount_reg <= 26'd0;
    redlgt_offcount_reg <= 16'd0;
    end
  else if(redlgt_offcount_reg < REDLGT_REQOFF_THD)
    begin
    redlgt_tcount_reg <= redlgt_tcount_reg + 1'b1;
    if(sw_in)
      redlgt_offcount_reg <= redlgt_offcount_reg + 1'b1;
    end
  else 
    begin
    redlgt_tcount_reg <= 26'd0;
    redlgt_offcount_reg <= 16'd0;
    redlgt_req_flag <= 1'b0;      //off redlgt request
    end
  end

assign sw_state=redlgt_req_flag;

endmodule


  
