package problem944

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test(t *testing.T) {
	tests := []struct {
		name     string
		elements []string
		want     int
	}{
		{
			name:     "case 1",
			elements: []string{"cba", "daf", "ghi"},
			want:     1,
		},
		{
			name:     "case 2",
			elements: []string{"a", "b"},
			want:     0,
		},
		{
			name:     "case 3",
			elements: []string{"zyx", "wvu", "tsr"},
			want:     3,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			minDeletionSize(tt.elements)
			require.Equal(t, tt.want, minDeletionSize(tt.elements), tt.name)
		})
	}
}
