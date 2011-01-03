

Scale = PageHeight / (4*SourceWidth)

xof = SourceHeight
yofRA = 0
yofRB = SourceWidth
yofVA = 0
yofVB = SourceWidth

rot1 = 90;
rot2 = 270;

tw = (PageHeight / 4) / Scale;
th = (PageWidth / 2) / Scale;
pgroup = 16;
do
	rest = PageCount % 16
	totp = PageCount
	if rest ~= 0
		then 
		totp = totp + ( 16 - rest)
		end
	inc = 0
	count = 0
	imax = totp/16
	while count < imax
		do
-- 		We assume that podofoimpose will discard invalid records
-- 		such as those with source page greater than PageCount
-- 		print(totp, inc, rot, xof,yofRA, yofRA, yofVA, yofVB)
-- Recto
		PushRecord((pgroup*count)+9, (count*2)+1, rot2, 0, tw)
		PushRecord((pgroup*count)+16, (count*2)+1, rot1, 2*th, 0)
		PushRecord((pgroup*count)+13, (count*2)+1, rot1, 2*th, 3*tw)
		PushRecord((pgroup*count)+12, (count*2)+1, rot2, 0, 4*tw)
		PushRecord((pgroup*count)+1, (count*2)+1, rot1, 2*th, tw)
		PushRecord((pgroup*count)+8, (count*2)+1, rot2, 0, 2*tw)
		PushRecord((pgroup*count)+4, (count*2)+1, rot1, 2*th, 2*tw)
		PushRecord((pgroup*count)+5, (count*2)+1, rot2, 0, 3*tw)
				
-- Verso
		PushRecord((pgroup*count)+10, (count*2)+2, rot1, 2*th, 0)
		PushRecord((pgroup*count)+15, (count*2)+2, rot2, 0, tw)
		PushRecord((pgroup*count)+11, (count*2)+2, rot1, 2*th, 3*tw)
		PushRecord((pgroup*count)+14, (count*2)+2, rot2, 0, 4*tw)
		PushRecord((pgroup*count)+7, (count*2)+2, rot1, 2*th, tw)
		PushRecord((pgroup*count)+2, (count*2)+2, rot2, 0, 2*tw)
		PushRecord((pgroup*count)+6, (count*2)+2, rot1, 2*th, 2*tw)
		PushRecord((pgroup*count)+3, (count*2)+2, rot2, 0, 3*tw)

		
		count = count + 1
		inc = inc + 8
		end
end

