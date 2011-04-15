---Generic Booklet (A4)
---
---It is said generic as it will try to determine
---automatically how to fit the booklet onto A4
---paper sheets, scaling pages if necessary. 
---it is well suited for office documents for
---which you do not care too much about resulting
---imposition artefacts since it manages to save 
---paper!
---
-- print("Booklet")
-- We output an A4 booklet
PageWidth = 595.27559
PageHeight = 841.88976

print("PageCount",PageCount)

-- We assume that H > W
-- Argh, we now can do better since we have "if" ;-)
-- Scale = PageHeight / (2*SourceWidth)
if(SourceWidth <= SourceHeight)
then
	Scale = PageHeight / (2*SourceWidth)
	rot = 90
		xof = SourceHeight
		yofRA = 0
		yofRB = SourceWidth
		yofVA = 0
		yofVB = SourceWidth
else
	Scale = PageHeight / (2*SourceHeight)
	rot = 0
		xof = 0;
		yofRA = 0
		yofRB = SourceHeight
		yofVA = SourceHeight
		yofVB = 0
end

do
	rest = PageCount % 4
	totp = PageCount
	if rest ~= 0
		then 
		totp = totp + ( 4 - rest)
		end
	inc = 0
	count = 0
	imax = totp/4
	while count < imax
		do
-- 		We assume that podofoimpose will discard invalid records
-- 		such as those with source page greater than PageCount
-- 		print(totp, inc, rot, xof,yofRA, yofRA, yofVA, yofVB)
-- Recto
		PushRecord(totp - inc , inc + 1 , rot, xof , yofRA)
		PushRecord(inc + 1 , inc + 1 , rot, xof , yofRB)
-- Verso
		PushRecord(inc + 2 , inc + 2 , rot, xof , yofVA)
		PushRecord(totp-(inc + 1) , inc + 2 , rot, xof, yofVB)
		
		count = count + 1
		inc = inc + 2
		end
end
