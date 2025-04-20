#!/usr/bin/env bash

# Test driver for ft_tail vs. system tail -c
# Requires: bash, tail, printf, diff, wc, hexdump

FTTAIL=./ft_tail      # Path to your ft_tail binary
TMPDIR=$(mktemp -d)
PASS=0
FAIL=0

# ANSI color codes
GREEN='\033[0;32m'    # green text :contentReference[oaicite:0]{index=0}
RED='\033[0;31m'      # red text   :contentReference[oaicite:1]{index=1}
NC='\033[0m'          # no color   :contentReference[oaicite:2]{index=2}

run_test() {
  local name="$1"; shift
  local cmd="$*"
  local ref_out="$TMPDIR/ref_${name}.out"
  local my_out="$TMPDIR/my_${name}.out"
  local exit_ref exit_my

  # Reference: run system tail
  eval "${cmd//FTTAIL/tail}"  >"$ref_out" 2>&1
  exit_ref=$?

  # Test: run your ft_tail
  eval "${cmd//FTTAIL/$FTTAIL}"  >"$my_out"   2>&1
  exit_my=$?

  if diff -u "$ref_out" "$my_out" >/dev/null && [ $exit_ref -eq $exit_my ]; then
    # Green PASS
    echo -e "${GREEN}PASS:${NC} $name"
    ((PASS++))
  else
    # Red FAIL
    echo -e "${RED}FAIL:${NC} $name"
    echo "  Command: $cmd"
    echo "  Expected (exit $exit_ref):"
    sed 's/^/    /' "$ref_out"
    echo "  Got (exit $exit_my):"
    sed 's/^/    /' "$my_out"
    ((FAIL++))
  fi
}

###############################################################################
# 1) Basic text, last 5 bytes
run_test basic_text  'printf "Hello World\n" | FTTAIL -c 5'

# 2) Input smaller than N
run_test small_input 'printf "abc" | FTTAIL -c 5'

# 3) Zero-byte request
printf "foo\n" >"$TMPDIR/f3.txt"
run_test zero_bytes   'FTTAIL -c 0 '"$TMPDIR"'/f3.txt'

# 4) Binary data
run_test binary       'printf "\x00\x01\x02\x03\x04\x05" | FTTAIL -c 3 | hexdump -v -e "%02x"'

# 5) File shorter than N
printf "1234567890" >"$TMPDIR/f5.bin"
run_test larger_file  'FTTAIL -c 100 '"$TMPDIR"'/f5.bin'

# 6) Multiple files
printf "aaaaa" >"$TMPDIR/f6a"
printf "12345" >"$TMPDIR/f6b"
run_test multi_file   'FTTAIL -c 3 '"$TMPDIR"'/f6a '"$TMPDIR"'/f6b'

# 7) Non-seekable input (pipe)
run_test pipe_input   'yes x | head -n 10000 | FTTAIL -c 1024 | wc -c'

# 8) Invalid +N usage
#run_test plus_syntax  'FTTAIL -c +5 '"$TMPDIR"'/f5.bin'

# 9) Missing file error
run_test missing_file 'FTTAIL -c 5 '"$TMPDIR"'/no_such_file'

# 10) Exact boundary and wrap
dd if=/dev/zero bs=1 count=16 of="$TMPDIR/f10.bin" 2>/dev/null
run_test exact_bound  'FTTAIL -c 16 '"$TMPDIR"'/f10.bin | wc -c'

###############################################################################
# Summary
echo
echo "======================================"
if [ $FAIL -eq 0 ]; then
  echo -e "${GREEN}All tests passed! (${PASS} passed)${NC}"
else
  echo -e "${RED}Some tests failed (${FAIL} failed, ${PASS} passed)${NC}"
fi
echo "======================================"

# Clean up
rm -rf "$TMPDIR"
