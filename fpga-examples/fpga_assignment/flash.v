module flash(
	input A,
	input B,
	input C,
	output wire r,
	output wire g,
	output wire b,
);
reg r,g.b;
always@(A,B,C)
begin
	r=A || C;
	g= A || (!A&&C)||(B&&C);
	b= (r&&g)||(!r&&!g);
end
endmodule
