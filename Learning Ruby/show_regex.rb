def show_regexp(a, re)
	if a =~ re
		"#{$`}<<#{$&}>>#{$'}"
	else
		"no match"
	end
end