import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
from dataclasses import dataclass
from typing import List, Optional

@dataclass
class MyPlotLib:
    def histogram(self, data, features):
        """
        Plots one histogram for each numerical feature in the list.
        Drop duplicate athletes to count only unique individuals.
        """
        # Drop duplicates based on 'Name' to count each athlete only once
        unique_data = data.drop_duplicates(subset=['Name'])
        
        for feature in features:
            plt.hist(unique_data[feature].dropna(), bins=30, alpha=0.5, label=feature)
        plt.legend()
        plt.show()

    def density(self, data, features):
        """
        Plots one density plot for each numerical feature in the list.
        Drop duplicate athletes to count only unique individuals.
        """
        # Drop duplicates based on 'Name' to count each athlete only once
        unique_data = data.drop_duplicates(subset=['Name'])
        
        for feature in features:
            unique_data[feature].dropna().plot(kind='density', label=feature)
        plt.legend()
        plt.show()

    def pair_plot(self, data, features):
        """
        Plots a matrix of subplots. On each subplot shows a scatter plot of one numerical
        variable against another one. The main diagonal of this matrix shows simple histograms.
        """
        unique_data = data.drop_duplicates(subset=['Name'])
        num_features = len(features)
        fig, axes = plt.subplots(nrows=num_features, ncols=num_features, figsize=(5*num_features, 5*num_features))
        for i, feature_x in enumerate(features):
            for j, feature_y in enumerate(features):
                if i == j:
                    unique_data[feature_x].dropna().hist(ax=axes[i, j], bins=30, alpha=0.5)
                else:
                    unique_data.plot.scatter(x=feature_x, y=feature_y, ax=axes[i, j])
        plt.tight_layout()
        plt.show()
    
    def box_plot(self, data, features):
        """
        Plots one box plot for each numerical feature in the list.
        Drop duplicate athletes to count only unique individuals.
        """
        # Drop duplicates based on 'Name' to count each athlete only once
        unique_data = data.drop_duplicates(subset=['Name'])
        
        unique_data[features].plot.box()
        plt.show()