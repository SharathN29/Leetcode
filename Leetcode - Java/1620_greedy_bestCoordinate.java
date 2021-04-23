// https://leetcode.com/problems/coordinate-with-maximum-network-quality/

class Solution {
    public int[] bestCoordinate(int[][] towers, int radius) {
        int maxNeworkQuality = Integer.MIN_VALUE;
        int[] maxCoordinate = new int[2];

        for(int i = 0; i < towers.length; i++) {
            int networkQuality = 0;
            for(int j = 0; j < towers.length; j++) {
                double dist = Math.sqrt(Math.pow(towers[j][0] - towers[i][0], 2) + Math.pow(towers[j][1] - towers[i][1], 2));

                if (dist <= radius) {
                    int signalQuality = (int) Math.floor(towers[j][2] / (1 + dist));
                    networkQuality += signalQuality;

                }
            }
            if (networkQuality > maxNeworkQuality) {
                maxNeworkQuality = networkQuality;
                maxCoordinate = new int[]{towers[i][0], towers[i][1]};
            }
            else if (networkQuality == maxNeworkQuality) {
                if (towers[i][0] == maxCoordinate[0]) {
                    if (towers[i][1] < maxCoordinate[1]) {
                        maxCoordinate = new int[]{towers[i][0], towers[i][1]};
                    }
                } else if (towers[i][0] < maxCoordinate[0]) {
                    maxCoordinate = new int[]{towers[i][0], towers[i][1]};
                }
            }
        }

        return maxCoordinate;
    }
}