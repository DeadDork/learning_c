#!/bin/sh

remove_asc() {
	for file in *; do
		if [[ "${file}" == *.asc ]]; then
			rm "${file}"
		fi
	done
}

# main {{{
# local
remove_asc

cd level_uno
remove_asc

cd level_dos
remove_asc

remove_asc
# main }}}
